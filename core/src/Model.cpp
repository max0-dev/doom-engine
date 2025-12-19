#include<Scene/Model.h>

#include<extern.h>

void Model::processNode(aiNode* node, const aiScene* scene){
    for(int i = 0; i < node->mNumMeshes; i++){
        const auto& mesh = scene->mMeshes[node->mMeshes[i]];

        if(!mesh->HasFaces()){
            spdlog::error("[ASSIMP] Target model doesn't include any faces!");
            continue;
        }
        if(!mesh->HasNormals()){
            spdlog::error("[ASSIMP] Target model doesn't include any normals!");
            continue;
        }
        bool hasCoords = false;
        unsigned int channel;
        for(int uvc = 0; uvc < mesh->GetNumUVChannels(); uvc++){
            if(mesh->HasTextureCoords(uvc)){
                
                hasCoords = true;
                channel = uvc;
            }
        }
        if(!hasCoords){
            spdlog::error("[ASSIMP] Target model doesn't include any texture coordinates!");
            continue;
        }

        std::vector<float> vertices;
        std::vector<unsigned int> indices;

        for(int vert = 0; vert < mesh->mNumVertices; vert++){
            const auto& vertex = mesh->mVertices[vert];
            const auto& normal = mesh->mNormals[vert];
            const auto& uv = mesh->mTextureCoords[channel][vert];

            vertices.push_back(vertex.x);
            vertices.push_back(vertex.y);
            vertices.push_back(vertex.z);

            vertices.push_back(normal.x);
            vertices.push_back(normal.y);
            vertices.push_back(normal.z);

            vertices.push_back(uv.x);
            vertices.push_back(uv.y);
        }

        for(int f = 0; f < mesh->mNumFaces; f++){
            const auto& face = mesh->mFaces[f];

            for(int ind = 0; ind < face.mNumIndices; ind++){
                unsigned int indice = face.mIndices[ind];
                indices.push_back(indice);
            }
        }

        mMeshes.emplace_back(vertices, indices);
    }

    for(int i = 0; i < node->mNumChildren; i++){
        processNode(node->mChildren[i], scene);
    }
}

Model::Model(const std::string& filepath){
    Assimp::Importer importer;

    const aiScene* scene = importer.ReadFile(filepath, aiProcess_FlipUVs | aiProcess_Triangulate | aiProcess_GenUVCoords);

    if(!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode){
        spdlog::error("[ASSIMP] Error while loading a model");
        return;
    }
    std::string directory = filepath.substr(0, filepath.find_last_of('/'));

    processNode(scene->mRootNode, scene);

    spdlog::info("[ASSIMP] Successfully loaded a model into memory!");
}

void Model::Render(VertexArray& vao){
    for(auto& mesh : mMeshes){
        mesh.Draw(vao);
    }
}