#include <fstream>
#include <string>
#include <sstream>

struct shaderProgramSource
{
    std::string VertexSource;
    std::string FragmentSource;
};

static shaderProgramSource ParseShader(const std::string& filepath)
{
    std::ifstream stream(filepath);

    enum class ShaderType
    {
        NONE = -1, VERTEX = 0, FRAGMENT = 1
    };

    std::string line;
    std::stringstream ss[2];
    ShaderType type = ShaderType::NONE;

    while (getline(stream, line))
    {
        if (line.find("#shader") != std::string::npos)
        {

            if (line.find("vertex") != std::string::npos)  // set to vertex    
                type = ShaderType::VERTEX;
            else if (line.find("fragment") != std::string::npos) // set to fragment          
                type = ShaderType::FRAGMENT;

        }
        else
        {
            ss[(int)type] << line << '\n';
        }
    }

    return { ss[0].str(), ss[1].str() };
}

