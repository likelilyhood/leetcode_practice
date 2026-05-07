#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

vector<long long> readLineNumbers() {
    string line;
    getline(cin, line);

    stringstream ss(line);
    vector<long long> nums;
    long long x;

    while (ss >> x) {
        nums.push_back(x);
    }

    return nums;
}

int main() {
    vector<long long> in_data = readLineNumbers();
    vector<long long> in_shape = readLineNumbers();
    vector<long long> kernel_data = readLineNumbers();
    vector<long long> kernel_shape = readLineNumbers();
    vector<long long> group_line = readLineNumbers();

    if (in_shape.size() != 4 || kernel_shape.size() != 4 || group_line.size() != 1) {
        cout << -1 << endl;
        cout << -1 << endl;
        return 0;
    }

    long long batch = in_shape[0];
    long long in_channels = in_shape[1];
    long long height = in_shape[2];
    long long width = in_shape[3];

    long long out_channels = kernel_shape[0];
    long long k_channels = kernel_shape[1];
    long long kernel_h = kernel_shape[2];
    long long kernel_w = kernel_shape[3];

    long long groups = group_line[0];

    long long in_size = batch * in_channels * height * width;
    long long kernel_size = out_channels * k_channels * kernel_h * kernel_w;

    if ((long long)in_data.size() != in_size ||
        (long long)kernel_data.size() != kernel_size ||
        batch <= 0 ||
        in_channels <= 0 ||
        height <= 0 ||
        width <= 0 ||
        out_channels <= 0 ||
        k_channels <= 0 ||
        kernel_h <= 0 ||
        kernel_w <= 0 ||
        groups <= 0 ||
        in_channels % groups != 0 ||
        out_channels % groups != 0 ||
        k_channels != in_channels / groups ||
        height < kernel_h ||
        width < kernel_w) {
        cout << -1 << endl;
        cout << -1 << endl;
        return 0;
    }

    long long out_h = height - kernel_h + 1;
    long long out_w = width - kernel_w + 1;

    vector<long long> out_data(batch * out_channels * out_h * out_w, 0);

    long long in_per_group = in_channels / groups;
    long long out_per_group = out_channels / groups;

    for (long long b = 0; b < batch; b++) {
        for (long long oc = 0; oc < out_channels; oc++) {
            long long group_id = oc / out_per_group;
            long long in_start = group_id * in_per_group;

            for (long long oh = 0; oh < out_h; oh++) {
                for (long long ow = 0; ow < out_w; ow++) {
                    long long sum = 0;

                    for (long long ic = 0; ic < k_channels; ic++) {
                        long long real_ic = in_start + ic;

                        for (long long kh = 0; kh < kernel_h; kh++) {
                            for (long long kw = 0; kw < kernel_w; kw++) {
                                long long ih = oh + kh;
                                long long iw = ow + kw;

                                long long in_index =
                                    ((b * in_channels + real_ic) * height + ih) * width + iw;

                                long long kernel_index =
                                    ((oc * k_channels + ic) * kernel_h + kh) * kernel_w + kw;

                                sum += in_data[in_index] * kernel_data[kernel_index];
                            }
                        }
                    }

                    long long out_index =
                        ((b * out_channels + oc) * out_h + oh) * out_w + ow;

                    out_data[out_index] = sum;
                }
            }
        }
    }

    for (long long i = 0; i < (long long)out_data.size(); i++) {
        if (i != 0) {
            cout << " ";
        }
        cout << out_data[i];
    }
    cout << endl;

    cout << batch << " " << out_channels << " " << out_h << " " << out_w << endl;

    return 0;
}