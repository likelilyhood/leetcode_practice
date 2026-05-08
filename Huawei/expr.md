

一类是**传统算法 / 数据结构题**，比如滑动窗口、DP、并查集、KNN、排序筛选、决策树推理。
另一类是**机器学习模拟题**，比如逻辑回归、K-means、卷积、Attention、线性回归、量化、MLP 反向传播等。

---

# 一、传统算法类

## 1. 最长无重复字符子串

题目：给一个字符串，求最长不含重复字符的子串长度。

核心算法：**滑动窗口 + last 位置数组**

关键点：

```text
窗口 [left, right] 始终保持无重复字符
last[c] 记录字符 c 上一次出现的位置
```

核心逻辑：

```cpp
if(last[c] >= left){
    left = last[c] + 1;
}
last[c] = right;
ans = max(ans, right - left + 1);
```

适用信号：

```text
最长连续子串
无重复字符
长度很大，比如 1e7
```

复杂度：

```text
O(n)
```

注意：

```text
不能暴力枚举子串
ASCII 字符可以开 last[128]
```

---

## 2. KNN 分类

题目：给待分类点，计算它和所有样本点距离，选最近 K 个，根据标签投票。

核心算法：**距离计算 + 排序 + 计数**

关键点：

```text
距离可以用平方距离，不用开根号
如果投票并列，返回并列标签中最近邻居的标签
```

实现结构：

```cpp
struct Sample {
    vector<double> x;
    int label;
    double dist;
};
```

流程：

```text
1. 读待分类样本
2. 遍历训练样本，计算距离
3. 按距离升序排序
4. 取前 k 个
5. 统计每个 label 数量
6. 找最大数量
7. 如果并列，从前 k 个最近点顺序扫描，第一个达到最大票数的 label 就是答案
```

最容易错：

```text
并列时不是选编号最小，而是选最近邻居对应的标签
输出的是 label 和该 label 在前 k 个邻居中的数量
```

---

## 3. 并查集：embedding 相似告警聚类

题目：每条告警有 embedding，余弦相似度 ≥ 0.95 就归为一类，并且满足传递性。

核心算法：**并查集 / 连通分量**

关键点：

```text
每条告警是一个点
两条告警相似，就连边
最后求最大连通分量大小
```

余弦相似度：

```text
cos = dot(a,b) / (norm(a) * norm(b))
```

并查集结构：

```cpp
vector<int> parent(n);
vector<int> sz(n, 1);
```

核心函数：

```cpp
int findRoot(int x){
    if(parent[x] == x){
        return x;
    }
    parent[x] = findRoot(parent[x]);
    return parent[x];
}
```

合并：

```cpp
if(sim >= 0.95){
    unite(i, j);
}
```

最容易错：

```text
输入可能为空，输出 0
不同 embedding 维度不一致，输出 0
全 0 向量不能除以 0
```

---

## 4. 决策树推理

题目：给一棵已经训练好的决策树，根据样本特征输出分类结果。

核心算法：**从根节点按条件往下走**

节点结构：

```cpp
struct Node {
    int feature;
    double threshold;
    int left;
    int right;
    int label;
};
```

流程：

```text
1. 每个样本从 cur = 0 或 cur = 1 的根节点开始
2. 如果当前节点是叶子，输出 label
3. 否则看 sample[feature] <= threshold
4. 成立走左子树，否则走右子树
```

临界条件：

```cpp
if(sample[featureIndex] <= threshold){
    cur = left;
}else{
    cur = right;
}
```

最容易错：

```text
等于阈值时走左边
节点编号可能从 0 开始，也可能从 1 开始，要看题目
叶子节点不要继续访问左右子节点
```

---

## 5. 决策树剪枝最大 F1

题目：给一棵未剪枝决策树，可以剪掉任意子树，把节点变成叶子，问验证集上最大 F1。

核心算法：**树形 DP + 状态合并**

关键点：

每个节点都可以有两种选择：

```text
1. 剪掉当前节点下面的子树，把当前节点当叶子
2. 不剪，继续使用左右子树
```

F1 公式：

```text
F1 = 2TP / (2TP + FP + FN)
```

因为总正样本数固定：

```text
FN = totalPositive - TP
```

所以状态只需要存：

```text
(TP, FP)
```

定义：

```text
dp[u] = 当前节点 u 的子树在所有剪枝方式下可能得到的 (TP, FP) 集合
```

转移：

```text
剪当前节点：
    如果 label[u] = 1:
        TP = 到达该节点的正样本数
        FP = 到达该节点的负样本数
    如果 label[u] = 0:
        TP = 0
        FP = 0

不剪：
    左子树状态 + 右子树状态两两合并
```

最容易错：

```text
不是普通推理题
每个内部节点也能被剪成叶子
F1 不是 accuracy
可以删除被支配状态：
如果 A.TP >= B.TP 且 A.FP <= B.FP，则 B 没用
```

---

# 二、动态规划类

## 6. 跳过扩散步骤，不能连续跳过

题目：有 T 个步骤，要跳过 k 个，跳过第 i 个有 loss，不能连续跳过，求最小 loss。

核心算法：**二维 DP**

状态：

```text
dp[i][j] = 前 i 个可跳过位置中，选择 j 个且不连续时的最小损失
```

转移：

```text
不选第 i 个：
dp[i][j] = dp[i-1][j]

选第 i 个：
dp[i][j] = dp[i-2][j-1] + loss[i]
```

初始化：

```cpp
dp[0][0] = 0;
dp[i][0] = 0;
```

可行性：

```text
如果有 n = T-1 个可跳过位置
最多可选 (n+1)/2 个
如果 k > (n+1)/2，输出 -1
```

最容易错：

```text
j = 0 时不能访问 j-1
loss 下标统一用 1-based 更稳
i == 1 且 j > 1 是非法状态
```

---

## 7. 量化方案选择：loss 约束下最小 mem

题目：每层选择 8bit 或 16bit，不同选择有 loss 和 mem，要求总 loss ≤ T，mem 最小。

核心算法：**分组背包**

状态：

```text
dp[loss] = 当前已处理若干层，在该 loss 下的最小 mem
```

每一层必须选一个方案，所以要用 `next_dp`：

```cpp
for each layer:
    next_dp 全 INF
    for old_loss:
        for each option:
            new_loss = old_loss + option_loss
            next_dp[new_loss] = min(next_dp[new_loss], dp[old_loss] + option_mem)
    dp = next_dp
```

小数处理：

```text
题目保留两位，可以 loss * 100 后 round 成整数
```

最容易错：

```text
不用 next_dp 会导致同一层重复选择
最后答案不是 dp[T]，而是 min(dp[0..T])
INF 不能用 INT16_MAX，应该用 1e18
```

---

## 8. 矩阵能量路径 DP

题目：先用策略矩阵计算每个位置能量，再在矩阵中按规则找最大路径。

核心分两步：

第一步：卷积 / 加权求和算能量矩阵 `erg[i][j]`

```cpp
for i
  for j
    sum = 0
    for k
      for l
        x = i + k - K/2
        y = j + l - K/2
        如果没越界:
            sum += img[x][y] * kernel[k][l]
```

第二步：DP 找路径。

如果路径从左到右，每次可以从左、左上、左下转移：

```text
dp[i][j] = 到达 (i,j) 的最大累计能量
```

转移：

```cpp
dp[i][j] = dp[i][j-1] + erg[i][j];

if(i > 0)
    dp[i][j] = max(dp[i][j], dp[i-1][j-1] + erg[i][j]);

if(i + 1 < H)
    dp[i][j] = max(dp[i][j], dp[i+1][j-1] + erg[i][j]);
```

最容易错：

```text
循环顺序必须先列后行：
for j
  for i

如果题目要求必须到最右列，答案是 max(dp[i][W-1])
不能取所有位置的最大值，否则中途停下会出错
```

---

# 三、排序筛选类

## 9. 专家路由：先选 NPU，再选专家

题目：n 个专家均分到 m 个 NPU，每组取最大概率代表该 NPU，选代表概率最大的 p 个 NPU，再从这些 NPU 的所有专家里选概率最大的 k 个专家，输出专家编号升序。

核心算法：**分组 + 排序 + 候选池筛选**

关键点：

```text
组数是 m
每组大小是 n / m
不是每组 m 个
```

结构体：

```cpp
struct Node {
    double score;
    int index;
};
```

分组：

```cpp
groups[i / groupSize].push_back({expert[i], i});
```

选 NPU：

```text
每组找最大 score
存成 {组最大 score, 组号}
按 score 降序排序
取前 p 个组号
```

候选池：

```cpp
for(int i = 0; i < selectedGroups.size(); i++){
    int gid = selectedGroups[i];

    for(int j = 0; j < groups[gid].size(); j++){
        candidates.push_back(groups[gid][j]);
    }
}
```

最终：

```text
候选专家按概率降序
取前 k 个专家编号
编号升序输出
```

最容易错：

```text
p 是选组，不是选专家
排序后要记住组号，所以要存 pair 或结构体
k > p * groupSize 时 error
```

---

# 四、机器学习模拟题

## 10. 逻辑回归

题目：用三特征预测是否购买，使用 sigmoid、交叉熵、L2 正则、梯度下降。

模型：

```text
z = w0*x0 + w1*x1 + w2*x2 + b
p = sigmoid(z)
```

sigmoid 稳定写法：

```cpp
double sigmoid(double z){
    if(z >= 0){
        return 1.0 / (1.0 + exp(-z));
    }else{
        double ez = exp(z);
        return ez / (1.0 + ez);
    }
}
```

交叉熵：

```text
loss = -[y*log(p) + (1-y)*log(1-p)]
```

梯度核心：

```text
diff = p - y
dw[j] += diff * x[j]
db += diff
```

L2 推荐写法：

```cpp
loss = loss / n + lambda * l2 / (2.0 * n);

dw[j] = dw[j] / n + lambda * w[j] / n;
db = db / n;
```

参数更新：

```cpp
w[j] -= alpha * dw[j];
b -= alpha * db;
```

终止条件注意：

```text
先用当前参数计算 loss
判断 abs(lastLoss - loss) < tol
若不停止，再更新参数
```

最容易错：

```text
特征用 double，不要用 int
标签用 int，不建议 bool
不要随便标准化，除非题目要求
tol 很大时可能只更新一轮
```

---

## 11. K-means 聚类

题目：给样本点，初始中心，迭代聚类，输出中心或每类数量。

核心流程：

```text
1. 初始中心一般取前 k 个样本
2. 每轮：
   sum 清零
   cnt 清零
   每个样本找最近中心
   加入该中心的 sum 和 cnt
   每个中心 = sum / cnt
3. 最后按题目要求输出
```

关键结构：

```cpp
struct Node {
    double h, w, x, y;
};
```

距离：

```cpp
double dist(Node a, Node b){
    double ans = 0;
    ans += (a.h - b.h) * (a.h - b.h);
    ans += (a.w - b.w) * (a.w - b.w);
    ans += (a.x - b.x) * (a.x - b.x);
    ans += (a.y - b.y) * (a.y - b.y);
    return ans;
}
```

最容易错：

```text
不能把旧中心直接拿来累加
每轮必须新建 sum 和 cnt
cnt 每轮要清零
用 double，不要用 int 截断中心
如果题目说迭代 n 次，就不要提前 break
```

---

## 12. YOLO / Anchor K-means

常见题型：

```text
给若干目标框宽高，用 K-means 找 anchor
距离用 1 - IoU
```

宽高 IoU：

```text
inter = min(w1,w2) * min(h1,h2)
union = w1*h1 + w2*h2 - inter
iou = inter / union
dist = 1 - iou
```

最容易错：

```text
anchor 聚类只看宽高，不看坐标
更新中心时注意重新计算平均宽高
输出排序时可以按面积 h*w 排序
```

---

## 13. 卷积 / 分组卷积 / 深度卷积

题目：给输入张量、卷积核、groups，手写前向传播。

输入形状：

```text
input:  [B, C, H, W]
kernel: [OC, KC, KH, KW]
output: [B, OC, OH, OW]
```

无 padding、stride = 1：

```text
OH = H - KH + 1
OW = W - KW + 1
```

一维展开下标：

```cpp
int in_index =
    ((b * C + real_ic) * H + ih) * W + iw;

int kernel_index =
    ((oc * KC + ic) * KH + kh) * KW + kw;

int out_index =
    ((b * OC + oc) * OH + oh) * OW + ow;
```

分组逻辑：

```cpp
int out_per_group = OC / groups;
int in_per_group = C / groups;

int group_id = oc / out_per_group;
int real_ic = group_id * in_per_group + ic;
```

深度卷积：

```text
groups = in_channels
```

最容易错：

```text
kernel 的第二维 KC = C / groups
groups = 1 时就是普通卷积
输出顺序一般是 [B][OC][OH][OW] 展平
输入如果按行给，要用 getline + stringstream
```

---

## 14. Attention 简化计算

题目：给 Attention 公式：

```text
Y = softmax(QK^T / h) V
```

特殊条件：

```text
X 全 1
W1,W2,W3 都是上三角全 1
softmax 简化为每行除以行和
```

关键结论：

```text
Q = K = V
Q、K、V 每一行都一样
QK^T 是常数矩阵
softmax 后每行都是 1/n
Y 等于 V 的行平均
但 V 每行一样，所以 Y = V
```

因此只需求：

```text
ans = n * sum_{j=1}^{h} min(m, j)
```

实现可以直接：

```cpp
long long rowSum = 0;

for(int j = 1; j <= h; j++){
    rowSum += min(m, j);
}

cout << n * rowSum << endl;
```

---

## 15. Softmax

标准公式：

```text
softmax_i = exp(x_i) / sum(exp(x_j))
```

稳定写法：

```text
先减去最大值 maxVal
再算 exp(x_i - maxVal)
```

适用场景：

```text
多分类概率
Attention 权重
类别概率归一化
```

注意：

```text
有些题会简化 softmax，不用 exp，只是每行除以行和
要按题目定义来
```

---

## 16. 线性回归：最小二乘正规方程

题目：3 个特征预测手机价格。

模型：

```text
price = w0 + w1*x1 + w2*x2 + w3*x3
```

关键点：加偏置项。

每个样本变成：

```text
[1, x1, x2, x3]
```

正规方程：

```text
w = (X^T X)^(-1) X^T y
```

代码里不直接求逆，而是解：

```text
A w = b

A = X^T X
b = X^T y
```

然后用高斯消元。

最容易错：

```text
忘记加常数 1
不要直接强转 int，要 llround 四舍五入
A 和 b 换行时必须一起换
```

---

## 17. 高斯消元

用途：解线性方程组。

步骤：

```text
1. 找当前列绝对值最大的主元
2. 把主元行换到当前行
3. 当前行除以主元，让主元变成 1
4. 用当前行消掉其它行当前列
```

关键代码结构：

```cpp
for(int col = 0; col < dim; col++){
    int pivot = col;

    for(int row = col + 1; row < dim; row++){
        if(fabs(A[row][col]) > fabs(A[pivot][col])){
            pivot = row;
        }
    }

    swap(A[pivot], A[col]);
    swap(b[pivot], b[col]);

    double div = A[col][col];

    for(int j = col; j < dim; j++){
        A[col][j] /= div;
    }
    b[col] /= div;

    for(int row = 0; row < dim; row++){
        if(row == col){
            continue;
        }

        double factor = A[row][col];

        for(int j = col; j < dim; j++){
            A[row][j] -= factor * A[col][j];
        }

        b[row] -= factor * b[col];
    }
}
```

边界：

```text
主元接近 0 时不可解或无唯一解
题目若保证解析解，一般不用特殊处理
```

---

## 18. MLP 前向 + MSE + 一次反向传播

题目：输入序列 `X[L][D]`，两层无偏置 MLP：

```text
H = X * W_mlp
Z = H * W_cls
y_pred = 对 L 个症状位置取平均
```

Loss：

```text
MSE = 1/K * sum((y_pred[k] - y_true[k])^2)
```

反向传播：

```text
grad_pred[k] = 2/K * (y_pred[k] - y_true[k])
grad_Z[i][k] = grad_pred[k] / L
grad_W_cls = H^T * grad_Z
grad_H = grad_Z * W_cls^T
grad_W_mlp = X^T * grad_H
```

更新：

```text
W_new = W_old - eta * grad
```

最容易错：

```text
y_pred 是对 L 求平均，不是对 K
loss 除以 K
grad_Z 要再除以 L
算 grad_H 时必须用更新前的 W_cls
```

---

## 19. INT8 非对称量化 + 全连接

题目：对 x 和 W 分别做 INT8 非对称量化，用量化整数做全连接，再反量化计算 MSE。

量化：

```text
scale = (max - min) / 255

q = clamp(round((v - min) / scale) - 128, -128, 127)
```

特殊：

```text
scale = 0 时，q = -128
```

反量化：

```text
deq = (q + 128) * scale + min
scale = 0 时，deq = min
```

全连接：

```text
Y = x * W^T
```

输出：

```text
第一行：x_quant 和 W_quant 计算得到的整数输出
第二行：MSE * 100000 四舍五入后的整数
```

最容易错：

```text
round 要用“就近取偶”，C++ round 不是这个
W 是整个矩阵统一量化，不是每一行单独量化
MSE 是原始浮点输出和反量化输出比较
```

---

## 20. 多分类混淆矩阵指标

题目：给 pred、trueY、weights，计算加权 precision、recall、F1。

混淆矩阵：

```text
conf[真实类别][预测类别]
```

对类别 c：

```text
TP = conf[c][c]
FP = 第 c 列除 conf[c][c] 之外的和
FN = 第 c 行除 conf[c][c] 之外的和
```

指标：

```text
precision = TP / (TP + FP)
recall = TP / (TP + FN)
f1 = 2 * precision * recall / (precision + recall)
```

加权：

```text
weightedPrecision += weights[c] * precision[c]
weightedRecall += weights[c] * recall[c]
weightedF1 += weights[c] * f1[c]
```

最容易错：

```text
F1 是每类先算 F1，再加权平均
不是先算加权 precision 和 recall 再算 F1
FP 是列方向
FN 是行方向
```

---

# 五、机考遇到陌生机器学习模拟题，该怎么拆

以后你看到机器学习名词，先别慌，按下面四问拆。

## 第 1 问：输入是什么形状？

比如：

```text
向量：vector<double>
矩阵：vector<vector<double>>
四维张量：一维数组 + 下标公式
树：结构体数组
图连通：并查集
```

## 第 2 问：核心公式是什么？

把公式翻译成循环。

例如：

```text
矩阵乘法：三层循环
卷积：多层循环
sigmoid：exp
softmax：exp + sum
距离：平方和
IoU：交集/并集
```

## 第 3 问：是否有迭代更新？

如果有：

```text
K-means：分配 → 更新中心
逻辑回归：算预测 → 算梯度 → 更新参数
MLP：前向 → loss → 梯度 → 更新权重
DP：上一层状态 → 下一层状态
```

## 第 4 问：答案从哪里取？

这个很关键。

例如：

```text
DP 是最后一列还是所有位置最大？
剪枝是根节点所有状态里最大 F1
K-means 是最终中心还是每类数量
路由是专家编号升序，不是概率顺序
```

---

# 六、合法“回溯骗分法”：怎么用暴力/搜索拿部分分

你说的“骗分”，我按**合法机考策略**理解：不会完整最优算法时，写一个能过小数据或部分数据的回溯/暴力版本，尽量拿分。这个是正当的解题策略，不是作弊。

## 1. 什么时候用回溯骗分

适合这些题：

```text
选或不选
排列组合
分组
剪枝
路径搜索
方案枚举
状态数量小
题目有多个子任务或隐藏小数据
```

不适合：

```text
n 很大，比如 1e5、1e7
矩阵大规模计算
必须 O(n log n) 的排序扫描题
```

---

## 2. 回溯的万能模板

```cpp
void dfs(int idx){
    if(idx == n){
        计算当前方案答案;
        更新全局最优;
        return;
    }

    // 不选
    dfs(idx + 1);

    // 选
    做选择;
    dfs(idx + 1);
    撤销选择;
}
```

适合：

```text
从 n 个东西中选若干个
剪枝/不剪枝
跳过/不跳过
选方案/不选方案
```

---

## 3. “选 k 个”的回溯模板

```cpp
void dfs(int idx, int chosen){
    if(chosen == k){
        计算答案;
        return;
    }

    if(idx == n){
        return;
    }

    // 剪枝：剩下的不够选
    if(chosen + (n - idx) < k){
        return;
    }

    // 不选 idx
    dfs(idx + 1, chosen);

    // 选 idx
    choose[idx] = 1;
    dfs(idx + 1, chosen + 1);
    choose[idx] = 0;
}
```

可以骗分的题：

```text
跳过 k 个步骤
选择 k 个专家/节点
小规模特征选择
```

---

## 4. “不能连续选”的回溯模板

```cpp
void dfs(int idx, int chosen, int lastChosen, int cost){
    if(chosen == k){
        ans = min(ans, cost);
        return;
    }

    if(idx == n){
        return;
    }

    if(chosen + (n - idx) < k){
        return;
    }

    // 不选
    dfs(idx + 1, chosen, 0, cost);

    // 选，要求上一个没选
    if(lastChosen == 0){
        dfs(idx + 1, chosen + 1, 1, cost + loss[idx]);
    }
}
```

对应你问过的“跳过步骤不能连续”。

---

## 5. 决策树剪枝的回溯骗分

如果不会树形 DP，可以枚举每个内部节点剪或不剪。

思路：

```text
1. 找所有非叶节点
2. 对每个非叶节点二选一：剪 / 不剪
3. 对验证集跑推理
4. 算 F1
5. 取最大
```

暴力复杂度：

```text
2^(内部节点数) * M * 树深
```

只能过小数据，但能拿部分分。

递归结构：

```cpp
void dfs(int idx){
    if(idx == internalCount){
        根据当前剪枝状态推理所有样本;
        计算 F1;
        更新 best;
        return;
    }

    // 不剪这个节点
    cut[node[idx]] = 0;
    dfs(idx + 1);

    // 剪这个节点
    cut[node[idx]] = 1;
    dfs(idx + 1);
}
```

推理时：

```text
如果当前节点被 cut，直接返回 label
否则按树继续走
```

---

## 6. K-means 不会写完整时的骗分

如果 K-means 卡住，最低限度可以写：

```text
1. 初始中心取前 k 个
2. 只迭代 1 次
3. 输出类别数量或中心
```

很多弱数据可能刚好只需要一轮。

但注意：

```text
sum 和 cnt 仍然要写对
```

---

## 7. DP 不会想时的回溯转 DP

如果题目像：

```text
每层选一个方案
总约束不超过 T
目标最小
```

你不会 DP，可以先写 DFS：

```cpp
void dfs(int layer, int loss, double mem){
    if(loss > T){
        return;
    }

    if(layer == L){
        ans = min(ans, mem);
        return;
    }

    for(int i = 0; i < optionCount[layer]; i++){
        dfs(layer + 1,
            loss + optionLoss[layer][i],
            mem + optionMem[layer][i]);
    }
}
```

这能过：

```text
层数小
每层选项少
约束小
```

如果要升级成 DP，再把：

```text
(layer, loss)
```

作为状态即可。

---

## 8. 回溯提速的几个小剪枝

### 剪枝 1：当前已经比答案差

```cpp
if(cost >= ans){
    return;
}
```

适合最小化题。

### 剪枝 2：剩余数量不够

```cpp
if(chosen + (n - idx) < k){
    return;
}
```

### 剪枝 3：约束超了

```cpp
if(loss > T){
    return;
}
```

### 剪枝 4：排序后优先选更可能好的

比如最小损失题，可以先按 loss 或 cost 排序，早点找到好答案。

---

## 9. 机考中回溯骗分的正确心态

你不能写注释说“骗分”，但可以合理写成：

```text
暴力搜索版本
适用于小规模数据
```

先保证能跑通样例和小数据，再考虑优化。

优先级：

```text
1. 输入输出完全正确
2. 小数据正确
3. 加剪枝
4. 有时间再改 DP / 贪心 / 并查集
```

如果算法没想出来，不要空着。写一个暴力版往往能拿不少隐藏小点分。

---

# 七、最后给你一个机考现场判断表

看到题目关键词时，直接联想：

```text
无重复最长子串 → 滑动窗口
相似度传递聚类 → 并查集
K 个最近点 → KNN + 排序
矩阵/权重/层 → 矩阵乘法
卷积核/通道/groups → 卷积多重循环
sigmoid/交叉熵 → 逻辑回归
中心/聚类/迭代 → K-means
剪枝/F1/树 → 树形 DP 或暴力回溯
选若干且有限制 → DP 或回溯
量化/INT8 → min/max/scale/round/clamp
线性回归/最小二乘 → 正规方程 + 高斯消元
precision/recall/F1 → 混淆矩阵
softmax/attention → 矩阵乘法 + 归一化
```
