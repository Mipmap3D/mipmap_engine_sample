#include "Reconstruct.h"
#include <iostream>
#include <fstream>
#include <string>
#include <json.hpp>

ReconstructCallBack cb(
    [](int finish) { return; },
    [](float progress) { std::cout << "[PROGRESS]" << progress * 100 << std::endl; },
    [](const std::string& message) {
        std::cout << message << std::endl;
    });

int main(int argc, char* argv[])
{
    nlohmann::json reconstruct_full_params;
    reconstruct_full_params["license_id"] = 9200;
    reconstruct_full_params["working_dir"] = "D:\\sample_test\\";
    reconstruct_full_params["gdal_folder"] = "C:\\data\\";
    reconstruct_full_params["resolution_level"] = 2; //1高分辨率  2中分辨率 3低分辨率
    reconstruct_full_params["generate_obj"] = true; // 生成obj格式的三维模型
    reconstruct_full_params["generate_ply"] = true; // 生成ply格式的三维模型
    reconstruct_full_params["generate_osgb"] = true; // 生成osgb格式的三维模型
    reconstruct_full_params["generate_3d_tiles"] = true; // 生成b3dm格式的三维模型tile
    reconstruct_full_params["generate_las"] = true; // 生成las格式的点云
    reconstruct_full_params["generate_pc_pnts"] = true; // 生成pnts格式的点云tile
    reconstruct_full_params["generate_geotiff"] = true; // 生成geotiff格式的2D产品(DOM+DSM)
    reconstruct_full_params["generate_tile_2D"] = true; // 2D产品切片
    reconstruct_full_params["input_image_type"] = 1; //1代表RGB影像

    // 影像组1(相机1拍摄)
    std::vector<std::string> file_group1 = {
        "D:\\sample_test\\photos\\DJI_20230727150826_0001_V.JPG",
        "D:\\sample_test\\photos\\DJI_20230727150827_0002_V.JPG",
        "D:\\sample_test\\photos\\DJI_20230727150829_0003_V.JPG" };
    // 影像组2(相机2拍摄)
    std::vector<std::string> file_group2 = {
        "D:\\sample_test\\photos\\DJI_20230727150831_0004_V.JPG",
        "D:\\sample_test\\photos\\DJI_20230727150832_0005_V.JPG",
        "D:\\sample_test\\photos\\DJI_20230727150836_0007_V.JPG" };

    std::vector<std::vector<std::string>> file_groups = { file_group1, file_group2 };
    nlohmann::json image_meta_data;
    int img_id = 0;
    for (int i = 0; i < file_groups.size(); ++i) {
        for (int j = 0; j < file_groups[i].size(); ++j) {
            nlohmann::json meta_data;
            meta_data["id"] = ++img_id;;
            meta_data["path"] = file_groups[i][j];
            meta_data["group"] = std::to_string(i);
            image_meta_data.push_back(meta_data);
        }
    }
    reconstruct_full_params["image_meta_data"] = image_meta_data;
    mipmap::ReconstructFull(reconstruct_full_params.dump(), cb);
    return 0;
}