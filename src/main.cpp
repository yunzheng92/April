
#include <vulkan/vulkan.h>
#include <spdlog/spdlog.h>
#include <spdlog/fmt/fmt.h>
#include <vector>
using namespace spdlog;

struct LayerProperties {
    VkLayerProperties                   properties;
    std::vector<VkExtensionProperties>  extensions;
};
int main(){
    info("hello vulkan");
    
    return 0;
}