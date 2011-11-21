#pragma once

#include "math/Vector3.h"
#include "graphics/Direct3D.h"

class Model;

struct MatrixBuffer {
    XMMATRIX worldViewProj;
};

class Shader {
public:
    Shader();
    ~Shader();
    bool Init(LPCWSTR shaderFile, LPCSTR vertexShaderName, LPCSTR pixelShaderName);
    void Shutdown();
    void UpdateConstants(XMMATRIX& mat);
    void Render(Model* model);

    ID3D11VertexShader* vertexShader;
    ID3D11PixelShader* pixelShader;
    ID3D11InputLayout* inputLayout;
    ID3D11Buffer* matrixBuffer;
};