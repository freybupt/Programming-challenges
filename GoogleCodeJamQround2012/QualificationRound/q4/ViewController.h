//
//  ViewController.h
//  googlecodeJam
//
//  Created by Liang Shi on 12-04-13.
//  Copyright (c) 2012 University of Alberta. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MirrorObject.h"
#import "HumanObject.h"

@interface ViewController : UIViewController{
    NSDictionary * letterDictionary;
}

@property (nonatomic, retain) NSDictionary * letterDictionary;


@end
