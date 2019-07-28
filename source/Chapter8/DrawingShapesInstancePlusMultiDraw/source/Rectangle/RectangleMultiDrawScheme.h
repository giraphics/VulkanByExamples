#pragma once
#include "../../../../common/VulkanApp.h"

#include "../../DrawingShapes_SceneGraph/RenderSchemeFactory.h"

class RectangleDescriptorSet;

class RectangleMultiDrawScheme : public RenderSchemeFactory
{
public:
    RectangleMultiDrawScheme(VulkanApp* p_VulkanApp);
    virtual ~RectangleMultiDrawScheme();

public:
    virtual void Setup();
    virtual void Update();
    virtual void Render(VkCommandBuffer& p_CommandBuffer);

    void ResizeWindow(VkCommandBuffer& p_CommandBuffer);
    virtual void Prepare(Scene* p_Scene);

private:
    void CreateGraphicsPipeline(bool p_ClearGraphicsPipelineMap = false);
    void CreateRectFillPipeline();
    void CreateRectOutlinePipeline();
    void CreateVertexLayoutBinding();

    void createPushConstants();

    virtual void UpdateNodeList(Node* p_Item);
    virtual void RemoveNodeList(Node* p_Model);

    enum RECTANGLE_GRAPHICS_PIPELINES
    {
        PIPELINE_FILLED = 0,
        PIPELINE_OUTLINE,
        PIPELINE_COUNT,
    };

    std::vector<VkVertexInputBindingDescription>   m_VertexInputBinding[PIPELINE_COUNT];   // 0 for (position and color) 1 for ()
    std::vector<VkVertexInputAttributeDescription> m_VertexInputAttribute[PIPELINE_COUNT]; // Why 7 = 2(for position and color) + 5 (transform and rotation) + Color

    typedef std::vector<Node*> NodeVector;
    NodeVector m_PipelineTypeModelVector[PIPELINE_COUNT];

    std::shared_ptr<RectangleDescriptorSet> m_DescriptorSet;
};
