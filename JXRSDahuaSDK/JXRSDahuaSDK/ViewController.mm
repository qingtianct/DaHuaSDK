//
//  ViewController.m
//  JXRSDahuaSDK
//
//  Created by tao cheng on 2018/11/2.
//  Copyright © 2018 tao cheng. All rights reserved.
//

#import "ViewController.h"
#include <dmu_sdk.h>
#include <ibp_error_enum.h>
#include <cmu_sdk.h>

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    CMU_SC_Init();
}


@end
