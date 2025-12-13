#include<fmt/core.h>
#include<spdlog/spdlog.h>
#include<iostream>
#include "test.h"

int main(int, char**){
    fmt::print("Hello, from Template!\n");
    spdlog::info("Hello, from spdlog!");

    Test test;

    std::cin.get();
}