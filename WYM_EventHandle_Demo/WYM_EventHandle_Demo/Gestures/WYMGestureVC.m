//
//  WYMGestureVC.m
//  WYM_EventHandle_Demo
//
//  Created by WalkerYm on 2017/9/8.
//  Copyright © 2017年 WalkerYm. All rights reserved.
//

#import "WYMGestureVC.h"

@interface WYMGestureVC ()

@end

@implementation WYMGestureVC

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
    
    UIPanGestureRecognizer *panGR = [[UIPanGestureRecognizer alloc] initWithTarget:self action:@selector(p_handlePanGR:)];
    [self.view addGestureRecognizer:panGR];
    
    
    UISwipeGestureRecognizer *swipeGR = [[UISwipeGestureRecognizer alloc] initWithTarget:self action:@selector(p_handleSwipeGR:)];
    [self.view addGestureRecognizer:swipeGR];
    
    
    
    
}


- (void)p_handlePanGR:(UIPanGestureRecognizer *)panGR{

    NSLog(@"发生了 panGR");
}

- (void)p_handleSwipeGR:(UISwipeGestureRecognizer *)swipeGR{

}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}
- (IBAction)handleTapGestureRecognizer:(UITapGestureRecognizer *)sender {
    
    NSLog(@"点击了视图");
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
