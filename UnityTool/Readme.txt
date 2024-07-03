import package to unity 2021.3.27f1

/*
 
- 为什么有它？
    这是一个分割图片的工具，很多Icon，UI元素都是以图集的形式出现，如果用别人的资源，没有合成图集前的一些数据，比如Icon位置，名称等等，所以这个工具就是为解决这个问题而生
 
- 怎么用它？
基本：
- 创建一个Unity工程文件
- 导入SpiltAltasToJson.unitypackage到工程文件内部
- 拥有你的图集资源

1.  将你的图集png导入到引擎内部
2.  指定你的图片为Sprite和Multiple类型
3.  去你的Sprite里用SpriteEditor进行手动框选分割图片或自动长度分割
4.  在S_Exec场景内的ExecSpriteToJason GameObject挂载SpriteToJson脚本（只要能让SpriteToJson脚本运行就行）
    S_Exec是运行此功能的环境，场景内ExecSpriteToJason GameObject挂载了运行脚本SpriteToJson，指定脚本Sprite和输出位置就行
5.  运行环境
6.  去你指定的路径去看json文件即可

- Why does it exist?
This is a tool for slicing images. Many icons and UI elements are presented in an atlas format. If you use resources from others without the data before the atlas was assembled, such as icon positions and names, this tool is designed to solve that problem.

- How to use it?

1.  Import your atlas PNG into the engine.
2.  Set your image to Sprite and Multiple types.
3.  Use the Sprite Editor to manually select and slice the images or use the automatic slicing feature in your Sprite.
4.  In the S_Exec scene, attach the SpriteToJson script to the ExecSpriteToJason GameObject (as long as you can run the SpriteToJson script).
    The S_Exec scene is the environment for running this function. The ExecSpriteToJason GameObject in the scene has the SpriteToJson script attached. You just need to specify the script's Sprite and output location.
5.  Run the environment.
6.  Check the JSON file in the specified path.

 */