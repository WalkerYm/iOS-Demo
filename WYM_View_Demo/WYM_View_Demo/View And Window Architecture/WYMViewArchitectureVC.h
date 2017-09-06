//
//  WYMViewArchitectureVC.h
//  WYM_View_Demo
//
//  Created by WalkerYm on 2017/9/6.
//  Copyright © 2017年 WalkerYm. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface WYMViewArchitectureVC : UIViewController

@end


/** 一、视图层次结构
 1. 视图层次结构 和 子视图管理：
    1）子视图和父视图；
    2）影响显示内容和对事件的响应。
 
 2. 视图绘制周期
    1）首次呈现，绘制其内容，系统获取快照，并将该快照作为视图的可视化表示；内容更改才重新绘制内容并捕获新的快照。（注：更改几何不会自动导致重绘视图内容，视图的 contentMode 属性确定如何响应对视图几何的更改。 大多数内容模式可以在视图的边界范围内拉伸或重新定位现有快照，并且不会创建新的快照。）
    2）告诉系统需要重绘的两个方法：setNeedsDisplay 或 setNeedsDisplayInRect：
        系统会在下一个 循环重新绘制；
    3） 系统视图通常实现私有绘图方法来呈现其内，对于自定义 UIView 子类，通常会覆盖视图的 drawRect：方法。还有其他方法来提供视图的内容，例如直接设置底层的内容，但是覆盖 drawRect：方法是最常见的技术。
 
 3. 视图的内容模式
    1）每个视图都有一个内容模式，用于控制视图如何回复其内容，以响应视图几何的变化以及是否根据视图的内容进行回收。
    2）执行以下操作，即可应用视图的内容模式：
        更改视图的 frame 或 bounds 矩形的宽度或高度。
        将包含缩放因子的变换分配给视图的 transform 属性。
 
 4. 可拉伸视图
    1）使用 contentStretch 属性创建；
    2）由 Core Animation layer 完成；
    3）要求为指定的内容模式；
 
 5. 支持内置动画
 
    1）UIView 对象中进行动画化的属性如下：
 frame - 使用它来为视图设置位置和大小更改。
 bounds - 使用它来动画更改视图的大小。
 center - 使用它来动画化视图的位置。
 transform - 使用它来旋转或缩放视图。
 alpha - 使用此来更改视图的透明度。
 backgroundColor - 使用此来更改视图的背景颜色。
 contentStretch - 使用它来更改视图的内容如何拉伸。
 
 */


/** 二、视图几何和坐标系统
 三种坐标系：屏幕坐标系统、窗口和视图定义的自定义坐标系。
 UIKit 默认的坐标系起点位于左上角；
 某些 iOS 技术定义原点和方向与 UIKit 使用的坐标系不同，Core Graphics 和 OpenGL ES 使用的坐标系的起点位于视图或窗口的左下角，其 y 轴相对于屏幕指向上方
 
 1. Frame，Bounds 和 Center 的关系
 
 当修改 frame 属性时，当大小被改变时，bounds 属性的值相对应被改变；当起点被改变时，center 属性的值相对应被改变；
 当修改 center 属性时，frame 的起点值相对应被改变；
 当修改 bounds 属性时，frame 的大小值相对应被改变；
 
 注：默认情况下，视图的 frame 不会剪切到其父视图的 frame。 因此，任何位于其父视野 frame 之外的子视图都将全部呈现。 但是，您可以通过将 superview 的 clipsToBounds属 性设置为YES来更改此行为。 无论子视图是否在视觉上被剪裁，触摸事件始终遵守目标视图的超视图的边界矩形。 换句话说，发生在位于其父视图边界矩形之外的视图的一部分中的触摸事件不会传递到该视图。
 
 
 2. 坐标系转换
    1）the affine transform
 要修改整个视图，请在视图的 transform 属性中修改仿射变换。
 要修改特定内容，在视图中的 drawRect：方法，请修改与活动图形上下文相关联的仿射变换。
    2）transform 属性不是用来做永久修改，修改视图的 transform 属性时，相对于视图的中心点执行所有转换。
    3）
    4）CTM
    5）每个子视图的坐标系建立在其祖先的坐标系上。 因此，当您修改视图的 transform 属性时，该更改会影响视图及其所有子视图。 但是，这些更改仅影响屏幕上视图的最终渲染。 因为每个视图都会绘制其内容并相对于自己的边界来排列其子视图，所以在绘制和布局过程中，它可以忽略其超级视图的变换。、
 
 3. 点与像素
    1）在 iOS 中，所有坐标值和距离都是使用指定为点（point）的单位的浮点值来指定的。
    2）一点不一定对应于屏幕上的一个像素。
    3）UIKit 和 Core Graphics 都使用基于矢量的绘图模型，其中所有坐标值都是使用点来指定的。
 */

/**
 
 三. 视图运行时的交互模型
 
 用户触摸屏幕开始到结束的流程：
 1）用户触摸屏幕；
 2）硬件向 UIkit 框架报告触摸事件；
 3）UIkit 框架将触摸事件包装到 UIEvent 对象中，并将其分派的指定的视图。（有关UIKit如何将事件发送到您的视图的详细说明，请参阅 Event Handling Guide for UIKit Apps.）
 4）在 view 中响应该触摸事件：如
    - 更改视图或其子视图的属性（frame、bounds、alpha 等等）；
    - 调用 setNeedsLayout 方法来标记视图需要布局更新；
    - 调用 setNeedsDisplay or setNeedsDisplayInRect: 来标记视图需要重绘；
    - 通知控制器更改一系列数据；
 5）如果由于任何原因改变视图的几何，UIKit 将根据一下规则更新其子视图：
    a. 若果配置 autoresizing 规则，UIKit 根据该规则调整视图；
    b. 如果视图实现layoutSubviews方法，UIKit将调用它。
 
 6）如果任何视图的任何部分被标记为需要重新绘制，则UIKit会将视图重新绘制。 对于显式定义drawRect：方法的自定义视图，UIKit调用该方法。
 7）任何更新的视图与应用程序的可见内容的其余部分进行合成，并发送到图形硬件进行显示。
 8）图形硬件将渲染的内容传输到屏幕。
 
 
 在上一组步骤中，您自己的自定义视图的主要集成点是：
 
 事件处理方法： 如果您使用手势识别器来处理事件，则不需要覆盖任何事件处理方法。
 - touchesBegan:withEvent
 - touchesMoved:withEvent:
 - touchesEnded:withEvent:
 - touchesCancelled:withEvent:
 
 如果您的视图不包含子视图或其大小不会更改，则无需重写layoutSubviews方法
 - The layoutSubviews method
 只有当视图的内容在运行时可以更改并且使用诸如UIKit或Core Graphics等本机技术来绘制时，才需要使用drawRect：方法。
 - The drawRect: method
 
 
 同样重要的是要记住，这些是主要的整合点，但不是唯一的。 UIView 类的几种方法被设计为子类的覆盖点。 您应该查看UIView类参考中的方法描述，以查看哪些方法可能适合您在自定义实现中覆盖。
 
 */


/**
    四、高效使用 View 的建议：
 1. 视图不总是有一个相应的视图控制器
 2. 尽量使用系统视图， 最小化自定义绘图；
 3. 利用内容模式，尽量减少视图重绘；
 4. 尽可能地将视图声明为不透明度
 5. 视图滚动时，调整视图的绘制行为；
 6. 不在标准的系统视图中添加子视图。
 
 */














