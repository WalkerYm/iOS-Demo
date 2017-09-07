//
//  WYMViewVC.h
//  WYM_View_Demo
//
//  Created by WalkerYm on 2017/9/7.
//  Copyright © 2017年 WalkerYm. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface WYMViewVC : UIViewController

@end



/** View
 视图对象是应用程序与用户交互的主要方式：
 - 布局和子视图管理；
 - 定义与父视图大小调整的行为；
 - 坐标系转换；
 - 绘图和动画；
 - 事件响应
 
 重点介绍创建，管理和绘制视图以及处理视图层次结构的布局和管理的步骤。
 */


/** 一、创建和配置视图对象
 1. 使用 IB 创建视图对象；
 2. 使用代码创建视图对象；
 3. 设置视图的属性；
    - alpha , hidden , opaque：不透明度
    - bounds, frame, center, transform：视图大小和位置；
    - autoresizingMask, autoresizesSubviews：子视图自动调整大小的行为；
    - contentMode, contentStretch, contentScaleFactor：视图内容的呈现行为；
    - gestureRecognizers, userInteractionEnabled, multipleTouchEnabled, exclusiveTouch：视图触摸事件；
    - backgroundColor, subviews, drawRect:method, layer, (layerClass method)：
 4. 为视图创建标签：tag；
 
 */


/** 二、创建和管理视图层次结构
 1. 添加和删除子视图
    - addSubview: 添加
    - insertSubview: 插入
    - parentSubviewToFront：，sendSubviewToBack：或exchangeSubviewAtIndex：withSubviewAtIndex： :重新排序现有的子视图。使用这些方法比删除子视图并重新插入更快。
    - removeFromSuperView：从父视图中移除（该方法由子视图调用）
 
 注：
 - clipsToBounds 属性设置为 YES 可以将子视图超出父视图的边界剪切掉。
 - removeFromSuperview 方法自动释放子视图，然后从其超级视图中删除它。
 
 将子视图添加到另一个视图时，UIKit会通知更改的父级和子级视图。 如果您实现自定义视图，则可以通过覆盖一个或多个willMoveToSuperview：，willMoveToWindow：willRemoveSubview：，didAddSubview：，didMoveToSuperview或didMoveToWindow方法来拦截这些通知
 
 2. 隐藏视图
 
 可以通过 hidden 属性，或更改 alpha 属性隐藏视图；
 隐藏的视图不会从系统接收到触摸事件。 但是，隐藏的视图确实参与与视图层次结构相关联的自动调整和其他布局操作。
 如果隐藏当前是第一个响应者的视图，则该视图不会自动撤销其第一个响应者状态，应该强制您的视图在您隐藏它时撤销第一个响应者状态
 
 3. 在视图层次结构中定位视图
 
 - 将指针存储在适合的位置，如控制器的属性。
 - 使用 tag 属性，并使用 viewWithTag： 方法来定位。
 
 
 4. 移动、缩放和旋转视图
 
 每个视图都有一个关联的仿射变换（affine transform），可以使用它来移动，缩放或旋转视图的内容。默认的仿射变换是标识变换，不会更改视图原有的外观，它改变的是视图最终的渲染外观。
 
 5. 在视图层次结构中转换坐标
 
 UIview 将坐标转换到视图的局部坐标系的方法：
 
    - convertPoint:fromView:
    - convertRect:fromView:
    - convertPoint:toView:
    - convertRect:toView:
 
 注：convert...：fromView：方法将坐标从一些其他视图的坐标系转换为当前视图的局部坐标系（bounds rectangle）。 相反，convert...：toView：方法将坐标从当前视图的局部坐标系（bounds rectangle）转换为指定视图的坐标系。 如果指定nil作为任何方法的参考视图，则转换是从包含视图的窗口的坐标系进行的。
 
 UIWindow 定义的转换方法：
    - convertPoint:fromWindow:
    - convertRect:fromWindow:
    - convertPoint:toWindow:
    - convertRect:toWindow:
 
 */


/** 三、运行时调整视图的大小和位置
 
 每当视图的大小发生变化时，其子视图的大小和位置都会发生相应的变化；
    - 自动布局：设置每个视图在其父视图调整大小时应遵循的规则
    - 手动布局：根据需要手动调整视图的大小和位置
 
 1. 布局变化的准备工作：
    - 视图 bounds 大小更改；
    - 屏幕界面变化，通常会触发根视图 bounds 变化；
    - 视图图层相关联的Core Animation layer的更改；
    - 调用 setNeedsLayout 或 layoutIfNeeded 方法；
    - 视图图层调用 setNeedsLayout 方法。
 
 2. 使用 Autoresizing 规则自动处理布局变化
 
 当视图的大小发生变化时，通常子视图的位置和大小也需要改变。
 autoresizesSubviews 属性决定了子视图是否调整大小，如果此属性设置为YES，则该视图将使用每个子视图的autoresizingMask属性来确定该子视图的大小和位置。 任何子视图的大小更改触发了嵌入式子视图的类似布局调整。
 
 
 - UIViewAutoresizingNone：
 - UIViewAutoresizingFlexibleHeight：当视图的高度变化时，视图的高度会发生变化。 如果不包括此常数，视图的高度不会改变。
 - UIViewAutoresizingFlexibleWidth：当视图的宽度更改时，视图的宽度会更改。 如果不包含此常量，视图的宽度不会改变。
 - UIViewAutoresizingFlexibleLeftMargin：视图的左边缘和超级视图的左边缘之间的距离根据需要增长或缩小。 如果不包括该常数，视图的左边缘将保持距离超视图左边缘的固定距离。
 - UIViewAutoresizingFlexibleRightMargin：视图右边缘和右侧边缘之间的距离根据需要增长或缩小。 如果不包括该常数，则视图的右边缘距离超级视图的右边缘保持固定的距离。
 - UIViewAutoresizingFlexibleBottomMargin：视图的底部边缘和超级视图的底部边缘之间的距离根据需要增长或缩小。 如果不包含该常数，则视图的底边距离超级视图的底部边缘保持固定的距离。
 - UIViewAutoresizingFlexibleTopMargin：视图的顶部边缘和超级视图的顶部边缘之间的距离根据需要增长或缩小。 如果不包括此常数，则视图的顶边缘距离超视图的顶部边缘保持固定距离。
 
 配置自动调整规则的最简单方法是使用 Interface Builder 的 the Size inspector 中的自动调整控件
 
 
 The easiest way to configure autoresizing rules is using the Autosizing controls in the Size inspector of Interface Builder. The flexible width and height constants from the preceding figure have the same behavior as the width and size indicators in the Autosizing controls diagram. However, the behavior and use of margin indicators is effectively reversed. In Interface Builder, the presence of a margin indicator means that the margin has a fixed size and the absence of the indicator means the margin has a flexible size. Fortunately, Interface Builder provides an animation to show you how changes to the autoresizing behaviors affect your view.
 配置自动调整规则的最简单方法是使用Interface Builder的“大小”检查器中的自动调整控件。 上图中灵活的宽度和高度常数与自动调整控件图中的宽度和大小指示符具有相同的行为。 然而，保证金指标的行为和使用有效地逆转了。 在界面生成器中，存在余量指示器意味着余量具有固定的大小，并且没有指示符意味着余量具有灵活的大小。 幸运的是，Interface Builder提供了一个动画来显示自动调整行为的变化如何影响您的视图。
 
 Important: If a view’s transform property does not contain the identity transform, the frame of that view is undefined and so are the results of its autoresizing behaviors.
 重要提示：如果视图的transform属性不包含标识变换，则该视图的框架是未定义的，并且其自动调整行为的结果也是如此。
 
 */


/** 3. 手动调整视图的布局
 
 每当视图的大小更改时，UIKit 应用该视图的子视图的自动调整行为，然后调用视图的 layoutSubviews 方法，以便进行手动更改。
 
 在该方法中执行以下任务：
    - 调整任何当前子视图的大小和位置；
    - 添加或删除子视图，添加或删除 Core Animation layers；
    - 标志子视图需要重绘（ setNeedsDisplay or setNeedsDisplayInRect:）
 
 One place where applications often lay out subviews manually is when implementing a large scrollable area. Because it is impractical to have a single large view for its scrollable content, applications often implement a root view that contains a number of smaller tile views. Each tile represents a portion of the scrollable content. When a scroll event happens, the root view calls its setNeedsLayout method to initiate a layout change. Its layoutSubviews method then repositions the tile views based on the amount of scrolling that occurred. As tiles scroll out of the view’s visible area, the layoutSubviews method moves the tiles to the incoming edge, replacing their contents in the process.
 应用程序通常手动布局子视图的一个地方是实现大型可滚动区域时。 因为为其可滚动内容拥有单个大视图是不切实际的，所以应用程序通常会实现包含多个较小的平铺视图的根视图。 每个平铺代表可滚动内容的一部分。 当滚动事件发生时，根视图调用其setNeedsLayout方法来启动布局更改。 它的layoutSubviews方法然后根据所发生的滚动量来重新定位平铺视图。 随着图块滚动到视图的可见区域之外，layoutSubviews方法将图块移动到传入边缘，替换其进程中的内容。
 
 
 
 编写布局代码时，请务必以下列方式测试代码：
 
 - 更改视图的方向，以确保布局在所有受支持的界面方向上看起来正确。
 - 确保您的代码适当地响应状态栏高度的更改。 当电话处于活动状态时，状态栏的高度会增加，当用户结束通话时，状态栏的大小会减小。
 
 see the ScrollViewSuite sample.
 */



/** 四、运行时修改视图
 
 当应用程序从用户接收输入时，他们会根据该输入调整用户界面。 应用程序可以通过重新排列它们，改变其大小或位置，隐藏或显示它们，或加载全新的视图来修改其视图。 在iOS应用程序中，您可以通过以下几种方式执行这些操作：
 

 视图控制器：
    - 视图控制器必须在显示他们之前创建它的视图（可以从 nib 文件加载或以编程方式创建），当不再需要时，将其释放；
    - 当设备方向变更时，视图控制器可能会调整视图的大小和位置以匹配。有可能会隐藏或新增一些视图。
    - 当视图控制器管理可编辑内容时，它可以在移动到编辑模式时调整其视图层次结构。 例如，它可能会添加额外的按钮和其他控件，以便于编辑其内容的各个方面。 这可能还需要调整任何现有视图的大小以适应额外的控制。
 
 在动画块中：
    - 在用户界面中不同的视图进行转换，可以在动画块中隐藏某个视图，并显示另外的视图；
    - 实现特殊的效果，可以修改视图的包含可动画性的属性；
 
 其他情况：
    - 有触摸事件或手势发生；
    - 与滚动视图进行交互；
    - 键盘出现。
 
 View controllers are a common place to initiate changes to your views. Because a view controller manages the view hierarchy associated with the content being displayed, it is ultimately responsible for everything that happens to those views. When loading its views or handling orientation changes, the view controller can add new views, hide or replace existing ones, and make any number of changes to make the views ready for the display. And if you implement support for editing your view’s content, the setEditing:animated: method in UIViewController gives you a place to transition your views to and from their editable versions.
 视图控制器是启动对视图进行更改的通用位置。 由于视图控制器管理与正在显示的内容相关联的视图层次结构，所以最终对这些视图发生的一切负责。 视图控制器加载视图或处理方向更改时，可以添加新视图，隐藏或替换现有视图，并进行任何更改以使视图准备好进行显示。 如果您实现了编辑视图内容的支持，则UIViewController中的setEditing：animated：方法可以让您将视图从可编辑的版本转换出来。
 
 Animation blocks are another common place to initiate view-related changes. The animation support built into the UIView class makes it easy to animate changes to view properties. You can also use the transitionWithView:duration:options:animations:completion: or transitionFromView:toView:duration:options:completion: methods to swap out entire sets of views for new ones.
 动画块是启动视图相关更改的另一个常见的地方。 UIView类内置的动画支持使得更改动画更容易查看属性。 您还可以使用transitionWithView：duration：options：animations：completion：或transitionFromView：toView：duration：options：completion：用于交换整组视图的新方法。
 
 */


/** 五、与  Core Animation Layers 交互
 
 每个视图对象都有一个专用的核心动画层，用于管理视图内容在屏幕上的呈现和动画。
 
 1. 更改视图关联的 Layer
    - 创建视图后，不能更改与视图关联的图层类型。
    - 使用 + (Class)layerClass 方法关联 Layer，该方法在视图的初始化前调用。
    - 每个视图建议只作为一个 layer 代理对象， 否则会导致应用程序中的绘制问题和潜在的崩溃
 
 2. 在视图中 嵌入 Layer 对象
    - 可以在视图中添加 Layer 对象；
    - Layer 对象不接收事件或参与响应者链，而是根据核心动画规则绘制自己并响应其父视图或图层中的大小更改。
    - Layer 对象必须添加到视图的 Layer 对象中
 
 
 */




/** 六、自定义视图
 
 
 如果标准系统视图不完全符合您的需要，您可以定义自定义视图。 自定义视图可以全面控制应用程序内容的外观，以及如何处理与该内容的交互。
 
 注：如果您使用OpenGL ES来绘制图形，则应使用GLKView类而不是将UIView子类化
 
 
 1. 实现自定义视图的清单：
    
 自定义视图的作用是呈现内容并管理与该内容的交互。 但是，成功实现自定义视图不仅涉及绘图和处理事件。 以下清单包括实现自定义视图时可以覆盖的更重要的方法（以及您可以提供的行为）：
    - 定义视图的初始化方法；
        - 计划以编程方式创建视图，覆盖 initWithFrame：方法或定义自定义初始化方法。
        - 计划从 nib 文件中加载的视图，请覆盖initWithCoder：方法。 使用此方法初始化视图并将其置于已知状态。
 
    - 实现 dealloc 方法来处理释放自定义的数据；
    - 覆盖 drawwRect：方法来处理绘制内容
    - 设置 autoresizingMask 属性来定义自动布局的行为；
 
 如果视图管理一个或多个子视图，需执行以下操作：
    - 在视图的初始化时，创建这些视图；
    - 在创建每个子视图时，设置 autoresizingMask 属性；
    - 如果您的子视图需要自定义布局，请覆盖layoutSubviews方法并在其中实现布局代码。
 
 为了响应触摸事件或手势：需要执行以下操作：
    - 使用 addGestureRecognizer: 添加合适手势；
 - 覆盖  touchesBegan:withEvent: , touchesMoved:withEvent:, touchesEnded:withEvent:, and touchesCancelled:withEvent:（不管其他方法是否覆盖，一定要覆盖 touchesCancelled:withEvent: 方法）
 
 If you want the printed version of your view to look different from the onscreen version, implement the drawRect:forViewPrintFormatter: method. For detailed information about how to support printing in your views, see Drawing and Printing Guide for iOS.
 
 
 2. 初始化视图
 
 - 代码初始化：initWithFrame：方法
 - nib 初始化：initWithCoder: 方法，还可以实现 awakeFromNib：方法，来做其他初始化
 
 
 3. 实现绘图代码
 对于自定义视图，需要覆盖 drawRect：方法，并在其中绘制图形。推荐使用自定义绘图作为最后的手段。 一般来说，如果您可以使用其他视图来呈现您的内容，则是首选。
 

 注意：
  - drawRect：方法应该只做一件事 -- 绘制内容；
  - 在调用 drawRect 方法前， UIKit 会为视图配置基本绘图环境，它创建一个图形上下文并调整坐标系和裁剪区域以匹配坐标系和视图的可见边界。可以使用UIGraphicsGetCurrentContext函数获取当前图形上下文的指针。
  - 当前图形上下文仅在对视图drawRect：方法的一次调用期间有效。 UIKit可能会为此方法的每个后续调用创建一个不同的图形上下文，因此您不应该尝试缓存对象并稍后使用。
  - 如果您知道您的视图的绘图代码始终以不透明的内容覆盖视图的整个表面，则可以通过将视图的opaque属性设置为YES来提高系统性能。 当您将视图标记为不透明时，UIKit避免绘制位于视图后面的内容。 这不仅减少了绘制时间，而且减少了将视图复合到其他内容时必须做的工作。 但是，只有当您知道视图的内容完全不透明时，才应将此属性设置为YES。 如果您的视图不能保证其内容始终不透明，则应将属性设置为NO。
  - 提高绘图性能的另一种方法，特别是在滚动时，是将视图的clearsContextBeforeDrawing属性设置为NO。 当此属性设置为YES时，UIKIt在调用您的方法之前，会自动使用drawRect：方法填充要使用透明黑色更新的区域。 将此属性设置为NO会消除该填充操作的开销，但会对您的应用程序造成负担，以填充传递给您的drawRect：方法的更新矩形的内容。
 
 
 
 
 4. 响应事件
 
 视图对象是响应者对象，即 UIResponder 类的实例，因此能接收触摸事件。当触摸事件发生时，窗口将相应的事件对象分发到发生触摸的视图。如果视图对事件不感兴趣，则可以忽略它或将其传递给其他响应者链，由另一个响应者对象来处理。
 
 除了直接处理触摸事件之外，视图还可以通过手势识别器来处理常见手势。
 
 touchesBegan:withEvent:
 touchesMoved:withEvent:
 touchesEnded:withEvent:
 touchesCancelled:withEvent:
 
 视图的默认行为是一次只响应一次触摸。 如果用户将第二根手指放下，系统将忽略触摸事件，不会将其报告给您的视图。 如果您计划从视图的事件处理程序方法跟踪多指手势，则需要通过设置multipleTouchEnabled来启用多点触摸事件您的观点属性为YES。
 
 
 
 Some views, such as labels and images, disable event handling altogether initially. You can control whether a view is able to receive touch events by changing the value of the view’s userInteractionEnabled property. You might temporarily set this property to NO to prevent the user from manipulating the contents of your view while a long operation is pending. To prevent events from reaching any of your views, you can also use the beginIgnoringInteractionEvents and endIgnoringInteractionEvents methods of the UIApplication
 object. These methods affect the delivery of events for the entire application, not just for a single view.
 一些视图（例如标签和图像）最初完全禁用事件处理。 您可以通过更改视图的userInteractionEnabled属性的值来控制视图是否能够接收触摸事件。 您可能会暂时将此属性设置为NO，以防止用户在长时间的操作待处理时操纵视图的内容。 为了防止事件达到您的任何视图，您还可以使用UIApplication的beginIgnoringInteractionEvents和endIgnoringInteractionEvents方法
 目的。 这些方法会影响整个应用程序的事件传递，而不仅仅是单个视图。
 
 Note: The animation methods of UIView typically disable touch events while animations are in progress. You can override this behavior by configuring the animation appropriately. For more information about performing animations, see Animations.
 注意：UIView的动画方法通常在动画进行过程中禁用触摸事件。 您可以通过适当地配置动画来覆盖此行为。 有关执行动画的更多信息，请参阅动画。
 
 As it handles touch events, UIKit uses the hitTest:withEvent: and pointInside:withEvent: methods of UIView
 to determine whether a touch event occurred inside a given view’s bounds. Although you rarely need to override these methods, you could do so to implement custom touch behaviors for your view. For example, you could override these methods to prevent subviews from handling touch events.
 在处理触摸事件时，UIKit使用hitTest：withEvent：和pointInside：withEvent：UIView的方法
 以确定在给定视图的边界内是否发生触摸事件。 虽然您很少需要重写这些方法，但您可以为此来实现自定义触摸行为。 例如，您可以覆盖这些方法，以防止子视图处理触摸事件。
 
 5. 清楚数据
 
 如果您的视图类分配任何内存，存储对任何自定义对象的引用，或者保存视图发布时必须释放的资源，则必须实现一个dealloc方法。 当您的视图的保留计数达到零时，系统将调用dealloc方法，现在是释放视图的时间。 您执行此方法应释放视图中保留的任何对象或资源，然后调用继承的实现，如清单3-5所示。 您不应该使用此方法执行任何其他类型的任务。
 
 
 */





































