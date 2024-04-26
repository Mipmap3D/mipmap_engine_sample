#include "Reconstruct.h"
#include <iostream>
#include <fstream>
#include <string>
#include <json.hpp>
#include <gflags/gflags.h>

ReconstructCallBack cb(
    [](int finish) { std::cout << "[FINISH]" << finish << std::endl; },
    [](float progress) { std::cout << "[PROGRESS]" << progress * 100 << std::endl; },
    [](const std::string& message) {
        std::cout << message << std::endl;
    });

DEFINE_int32(reconstruct_type, 0, "reconstruct_type");
DEFINE_string(task_json, "task.json", "task json");

int main(int argc, char* argv[])
{
    gflags::ParseCommandLineFlags(&argc, &argv, true);
    std::ifstream ifs(FLAGS_task_json);
    if (ifs.fail()) {
        return false;
    }
    std::string str((std::istreambuf_iterator<char>(ifs)), std::istreambuf_iterator<char>());
    mipmap::ReconstructFull(str, cb);
    return 0;
}
