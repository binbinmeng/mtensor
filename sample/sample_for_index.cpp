﻿#include <mtensor.hpp>

using namespace matazure;

int main(int argc, char* argv[]) {
    pointi<2> shape{5, 5};
    tensor<float, 2> ts_a(shape);
    tensor<float, 2> ts_b(shape);
    tensor<float, 2> ts_c(shape);
    fill(ts_a, 1.0f);
    fill(ts_b, 2.0f);

    //使用cuda  lambda算子 需要申明__device__ __host__
    auto functor = [=](pointi<2> idx) { ts_c(idx) = ts_a(idx) + ts_b(idx); };
    // // 计算
    for_index(shape, functor);

    std::cout << ts_c << std::endl;

    return 0;
}