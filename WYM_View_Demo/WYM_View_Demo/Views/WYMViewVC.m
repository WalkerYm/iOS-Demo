//
//  WYMViewVC.m
//  WYM_View_Demo
//
//  Created by WalkerYm on 2017/9/7.
//  Copyright © 2017年 WalkerYm. All rights reserved.
//

#import "WYMViewVC.h"

@interface WYMViewVC ()

@end

@implementation WYMViewVC

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.

    self.title = NSStringFromClass(self.class);
    
    UIView *subView = [[UIView alloc] initWithFrame:CGRectMake(0, 0, 100, 100)];
    [self.view addSubview: subView];
    
}

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
