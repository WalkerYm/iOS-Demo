//
//  WYMDetailVC.m
//  WYM_UIViewController_Demo
//
//  Created by WalkerYm on 2017/9/4.
//  Copyright © 2017年 WalkerYm. All rights reserved.
//

#import "WYMDetailVC.h"

static NSString *kTitleString = @"title";

@interface WYMDetailVC ()

@end

@implementation WYMDetailVC

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
    
    self.title = self.showText;
    self.restorationIdentifier = @"restorationIndentifier";
}


#pragma mark -状态记录
- (void)encodeRestorableStateWithCoder:(NSCoder *)coder{

    [super encodeRestorableStateWithCoder:coder];
    [coder encodeObject:self.showText forKey:kTitleString];
}

- (void)decodeRestorableStateWithCoder:(NSCoder *)coder{

    [super decodeRestorableStateWithCoder:coder];
    self.showText = [coder decodeObjectForKey:kTitleString];
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
