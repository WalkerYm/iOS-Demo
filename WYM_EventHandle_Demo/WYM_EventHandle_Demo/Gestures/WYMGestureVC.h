//
//  WYMGestureVC.h
//  WYM_EventHandle_Demo
//
//  Created by WalkerYm on 2017/9/8.
//  Copyright © 2017年 WalkerYm. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface WYMGestureVC : UIViewController

@end




/** 一、手势
 
 1. 手势识别器基础
 
 基本知识:
 1） 手势识别器是视图中处理触摸或按压事件的最简单的方法。 每个视图都可以关联一个或多个手势识别器。 手势识别器封装处理和解释该视图的传入事件所需的所有逻辑，并将其与已知模式进行匹配。 当检测到匹配时，手势识别器通知其分配的目标对象，其可以是视图控制器，视图本身或应用中的任何其他对象。 使用 target-action 设计模式发送通知。
 2） 手势识别器有两种类型：离散和连续。
    - 离散：离散手势识别器会调用您的动作方法一次。
    - 连续：连续的手势识别器可能会多次调用您的动作方法，包括在手势的开始和结束以及每次跟踪的事件的细节发生变化时。包括在手势的开始和结束以及每次跟踪的事件的细节发生变化时。
 3） 手势添加的方式：IB 或 代码。
 
 
响应手势：
  - 对于离散的手势，相当于按钮一样的响应；
  - 对于连续的手势：action 方法可以对手势做出相应的响应，也可以跟踪该手势在各个步骤的跟踪事件。
  - 手势识别器的状态：UIGestureRecognizerStateBegan、UIGestureRecognizerStateChanged、UIGestureRecognizerStateEnded
 
 2. 点击和长按手势
 
很多原因可以导致手势被取消：如 userInteractionEnabled 属性为 NO 时， numberOfTapsRequired 触点数不对， numberOfTouchesRequired
 
 UITapGestureRecognizer：
    - 离散手势：
    - 触点数；

 
 UILongPressGestureRecognizer:
 
    - 连续手势；

 
 
 
 3. 拖动 和 轻扫 手势
 
 UIPanGestureRecognizer：
    - 连续
 
 UISwipeGestureRecognizer：
    - 离散
 
 4. 捏合 和 旋转 手势：
 UIPinchGestureRecognizer:
    - 连续；
 
 
 
 UIRotationGestureRecognizer:
    - 连续
 
 
 
 5. 自定义手势
 
    1)子类化 UIGestureRecognizer；
    2）实现处理事件所需要的任何方法：
    - touchesBegan:withEvent:,
    - touchesMoved:withEvent:
    - touchesEnded:withEvent:
    - touchesCancelled:withEvent:
 
 手势识别器的状态机制：
 
   1）离散手势：
    - 实现离散手势识别器时，可以将state属性更改为两个可能的值之一：UIGestureRecognizerStateRecognized或UIGestureRecognizerStateFailed。
    - 当您的手势识别器转换为UIGestureRecognizerStateRecognized状态时，UIKit将调用任何关联的目标对象的操作方法。 当手势识别器转换到UIGestureRecognizerStateFailed状态时，UIKit不会调用任何操作方法。
 
 
    2）连续手势
 当实现连续的手势识别器时，您必须处理更多的状态转换。 连续手势识别器的状态图如图5-3所示。 你所做的状态转换可以分为三个一般阶段：
 
 初始事件将手势识别器移动到开始状态。
 随后的事件将手势识别器移动到“更改”状态。
 最后的事件结束了手势。
 
 
 当新的事件序列开始时，将您的手势识别器移动到UIGestureRecognizerStateBegan状态。您也可以使用手势的开始来缓存您需要跟踪手势的任何信息。对于任何后续事件，将您的手势识别器移动到UIGestureRecognizerStateChanged状态并更新任何缓存的值。将您的手势识别器保持在UIGestureRecognizerStateChanged状态，直到事件指示手势的成功或失败，此时将手势识别器移动到适当的状态。例如，您可以在手势识别器的touchesEnded：withEvent：方法中将状态设置为UIGestureRecognizerStateRecognized，以表示用户成功完成了手势。、
 
 当您的手势识别器转换到UIGestureRecognizerStateBegan，UIGestureRecognizerStateChanged或UIGestureRecognizerStateRecognized状态时，UIKit会调用任何关联目标的操作方法。当您的手势识别器转换到其他状态时，UIKit不会调用任何操作方法。
 
 当事件指示失败的手势时，立即将手势识别器移动到UIGestureRecognizerStateFailed状态。 UIKit通常只允许一个手势识别器通知其客户端。将自定义手势识别器移动到失败的状态，使其他手势识别器有机会通知客户端。
 
 3）处理手势中断；
 当系统取消手势时，UIKit会调用touchesCancelled：withEvent：或者pressCancelled：withEvent：手势识别器的方法。 当发生这种情况时，立即将您的手势识别器移动到UIGestureRecognizerStateCancelled状态，并执行任何所需的清理。 当您将手势识别器移动到该状态时，UIKit将停止调用手势识别器的相关操作方法。
 
 4）重置手势的状态机制
 实现重置方法并使用它来将您的手势识别器返回到其初始配置。 在以新事件序列发送事件之前，UIKit会调用接收到触摸的每个手势识别器的复位方法，或者在UIGestureRecognizerStateFailed，UIGestureRecognizerStateCancelled或UIGestureRecognizerStateRecognized状态中。 除了调用重置方法之外，UIKit还会自动将每个手势识别器的状态属性更改为UIGestureRecognizerStatePossible，以便它可以响应新的事件序列。
 
 
 
 实现一个离散的手势识别器：
    离散手势识别器的优点是它们更容易实现，因为它们需要更少的状态转换。 一个缺点在于，由于状态变化通常在事件序列中较晚发生，识别可以容易地通过连接到相同视图的连续手势来抢占。
 
 
 
 6. 解决手势冲突问题
 
 1）使用 UIGestureRecognizerDelegate 协议创建手势的优先级；
 2）允许多个手势同时生效
 3）在 UIKit 控件中添加手势。
 
 */




/** 二、Responders 和 Responder Chain
 
 应用程序使用 responder 对象接收和处理事件。响应者对象是 UIResponder 类的任何实例，常见的子类包括UIView，UIViewController和UIApplication。 UIKit自动管理大多数响应者相关的行为，包括事件如何从一个响应者传递到下一个。但是，您可以修改默认行为来更改事件在应用程序中的传送方式。
 
 
 UIKit将大多数事件引导到应用程序中最合适的响应者对象。如果该对象不处理该事件，UIKit将其转发到活动响应器链中的下一个响应器，该响应器链是应用程序的响应者对象的动态配置。因为它是动态的，您的应用程序中没有单个响应者链。然而，很容易确定链中的下一个响应者，因为事件总是从特定响应者对象流向更一般的响应者对象。例如，视图的下一个响应者是其超级视图或管理视图的视图控制器。事件继续流向响应者链，直到被处理。
 
 
 图7-1显示了一个应用程序链，其形式在其界面包含标签，文本字段，按钮和两个背景视图的应用程序中。如果文本字段不处理事件，则UIKit将事件发送到文本字段的父UIView对象，后跟窗口的根视图。从根视图，响应者链转移到拥有的视图控制器，然后返回到视图的窗口。如果窗口不处理该事件，则UIKit将事件传递给UIApplication对象，如果该对象是UIResponder的实例，并且还不是响应器链的一部分，则可能将该事件传递给应用程序委托
 
 对于每个事件，UIKit指定第一个响应者，并首先将事件发送到该对象。第一响应者根据事件的类型而不同。
 
 - 触摸事件。第一反应者是发生触摸的视图。
 - Press events：第一反应者是有关注的回应者；
 - Motion events：The first responder is the object that you designated to handle the events. Core Motion handles events related to the accelerometers, gyroscopes, and magnetometer. Motion events do not follow the responder chain.
 - Shake-motion events：第一个响应者是您（或UIKit）指定为第一个响应者的对象
 - Remote-control events：第一个响应者是您（或UIKit）指定为第一个响应者的对象
 - Editting-menu messages：第一个响应者是您（或UIKit）指定为第一个响应者的对象
 
 
 由控件发送到其关联对象的操作消息不是事件，但它们仍然可以利用响应器链。 当控件的目标对象为nil时，UIKit从目标对象中移走响应者链，并查找实现相应操作方法的对象。 例如，UIKit编辑菜单使用此行为来搜索实现名为cut :, copy :,或paste：的方法的响应者对象。
 如果视图具有附加的手势识别器，则手势识别器可以将触摸和按压事件的传送延迟到视图。 delayTouchesBegan，delayedTouchesEnded，并取消UIGestureRecognizerTouchesInView属性，确定触发延迟的时间和方式。
 
 
 
 
 */
































