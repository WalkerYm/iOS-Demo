
//
//  WYMPresentedVC.m
//  WYM_UIViewController_Demo
//
//  Created by WalkerYm on 2017/9/4.
//  Copyright © 2017年 WalkerYm. All rights reserved.
//

#import "WYMPresentedVC.h"
#import "WYMTransition.h"
#import "WYMInteractiveTransition.h"


@interface WYMPresentedVC ()<UIViewControllerTransitioningDelegate>

@property (nonatomic, strong) WYMInteractiveTransition *interactiveTransition;

@end

@implementation WYMPresentedVC

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
    
    self.title = NSStringFromClass(self.class);
    self.view.backgroundColor = [UIColor purpleColor];
    
    self.transitioningDelegate = self;
    self.modalPresentationStyle = UIModalPresentationCustom;
    
    self.interactiveTransition = [WYMInteractiveTransition wym_intertativeTransitionWithTransitionType:XWInteractiveTransitionTypeDismiss gestureDiraction:WYMInteractiveTransitionGestureDirectionDown];
    [self.interactiveTransition wym_addPanGestureForViewController:self];
}

- (IBAction)clickDismissBtn:(id)sender {
    
    
    [self dismissViewControllerAnimated:YES completion:nil];
    
}

#pragma mark - UIViewControllerTransitioningDelegate
- (nullable id <UIViewControllerAnimatedTransitioning>)animationControllerForPresentedController:(UIViewController *)presented presentingController:(UIViewController *)presenting sourceController:(UIViewController *)source{

    return  [WYMTransition wym_transitionWithTransitionType:WYMTransitonTypePresent];
}

- (nullable id <UIViewControllerAnimatedTransitioning>)animationControllerForDismissedController:(UIViewController *)dismissed{

     return  [WYMTransition wym_transitionWithTransitionType:WYMTransitonTypeDismiss];
}

- (nullable id <UIViewControllerInteractiveTransitioning>)interactionControllerForPresentation:(id <UIViewControllerAnimatedTransitioning>)animator{

    if ([_dataSource respondsToSelector:@selector(interactiveTransitionForPresent)]) {
        WYMInteractiveTransition *interactivePresent =  [_dataSource interactiveTransitionForPresent];
        return interactivePresent.interation ? interactivePresent : nil;
    }
    
    return nil;
}

- (nullable id <UIViewControllerInteractiveTransitioning>)interactionControllerForDismissal:(id <UIViewControllerAnimatedTransitioning>)animator{

    return  _interactiveTransition.interation ? _interactiveTransition : nil;
}

//- (nullable UIPresentationController *)presentationControllerForPresentedViewController:(UIViewController *)presented presentingViewController:(nullable UIViewController *)presenting sourceViewController:(UIViewController *)source NS_AVAILABLE_IOS(8_0);


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
