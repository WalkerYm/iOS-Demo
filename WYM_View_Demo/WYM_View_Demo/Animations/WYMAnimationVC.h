//
//  WYMAnimationVC.h
//  WYM_View_Demo
//
//  Created by WalkerYm on 2017/9/7.
//  Copyright © 2017年 WalkerYm. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface WYMAnimationVC : UIViewController

@end


/** Animation
 
 在 iOS 中，广泛使用动画来重新定位视图，更改大小，将其从视图层次结构中删除，并将其隐藏。 您可以使用动画向用户传达反馈或实现有趣的视觉效果。
 
 在iOS中，创建复杂的动画不需要您编写任何绘图代码。 本章中描述的所有动画技术都使用 Core Animation 提供的内置支持。 所有你需要做的是触发动画，让 Core Animation 处理单个帧的渲染。 这使得创建复杂的动画非常容易，只需几行代码。
 
 1. What Can Be Animated
 
 UIKit 和 Core Animation 都为动画提供支持，但每种技术所提供的支持水平各不相同。
 
 表4-1列出了 UIView 类的动画属性（内置动画支持的属性）。 动画不一定意味着动画会自动发生。 更改这些属性的值通常只是立即更新属性（和视图）而不需要动画。 要动画化此类更改，您必须从动画块内更改属性的值，
 
 - frame：修改此属性以更改视图的大小和位置相对于其父视图的坐标系。 （如果 transform 属性不包含 identity transform，请修改 bounds 或 center 属性。）
 - bounds：修改此属性以修改视图的大小；
 - center：修改此属性以更改相对父视图坐标系的视图位置；
 - transform：修改此属性以缩放，旋转或移动视图相对于其中心点。 使用此属性的变换始终在2D空间中执行。 （要执行3D转换，您必须使用Core Animation为视图的图层对象设置动画。）
 - alpha：修改次属性来逐渐修改视图的透明度；
 - backgroundColor：
 - contentStretch：修改此属性以更改视图内容的拉伸方式以填充可用空间。
 
 使用 Core Animation layer：
 
 - 层的大小和位置
 - 执行转换时使用的中心点
 - 在3D空间中转换到图层或其子图层
 - 从层次结构中添加或删除图层
 - 该层相对于其他兄弟层的Z顺序
 - 层的阴影
 - 图层的边框（包括图层的边角是否四舍五入）
 - 在调整大小操作期间该层的部分延伸
 - 层的不透明度
 - 位于层边界之外的子层的剪切行为
 - 当前内容的图层
 - 图层的光栅化行为
 
 
 */



































































