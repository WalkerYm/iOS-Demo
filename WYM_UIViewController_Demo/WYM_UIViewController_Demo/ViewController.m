//
//  ViewController.m
//  WYM_UIViewController_Demo
//
//  Created by WalkerYm on 2017/9/4.
//  Copyright © 2017年 WalkerYm. All rights reserved.
//

#import "ViewController.h"


static NSString * const kReusableCellIndentifier = @"cell";

@interface ViewController ()<UITableViewDataSource, UITableViewDelegate>


@property (weak, nonatomic) IBOutlet UITableView *tableView;
@property (nonatomic, strong) NSArray *dataArray;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    [self p_initTableView];
}

- (void)p_initTableView{

    
    self.tableView.delegate = self;
    self.tableView.dataSource = self;
    [self.tableView setTableFooterView:[[UIView alloc] initWithFrame:CGRectZero]];
    
    self.automaticallyAdjustsScrollViewInsets = NO;
    self.title = @"UIViewController";
}


#pragma mark - TableView Delegate
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section{

    return self.dataArray.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath{

    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:kReusableCellIndentifier];
    if (!cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleValue1 reuseIdentifier:kReusableCellIndentifier];
    }
    
    cell.textLabel.text = self.dataArray[indexPath.row];
    
    return cell;
}


- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath{

    
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
    UIViewController *subVC = [[NSClassFromString(self.dataArray[indexPath.row]) alloc] init];
    [self.navigationController pushViewController:subVC animated:YES];
}



#pragma mark - 懒加载
- (NSArray *)dataArray{

    if (!_dataArray) {
        _dataArray = @[@"WYMContainerVC", @"WYMPreservingVC", @"WYMPresentingVC", @"WYMPresentVC", @"WYMFistPresentationVC", @"WYMAdaptiveModelVC"];
    }
    
    return _dataArray;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
