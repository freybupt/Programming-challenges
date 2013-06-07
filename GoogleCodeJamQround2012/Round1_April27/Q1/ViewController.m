//
//  ViewController.m
//  googlecodeJam
//
//  Created by Liang Shi on 12-04-13.
//  Copyright (c) 2012 University of Alberta. All rights reserved.
//

#import "ViewController.h"

@implementation ViewController
@synthesize letterDictionary;


#pragma mark - View lifecycle

- (void)viewDidLoad
{
    [super viewDidLoad];
    NSString *result = @"";

    NSString* path = [[NSBundle mainBundle] pathForResource:@"A-small-attempt2" 
                                                     ofType:@"in"];
    NSString* content = [NSString stringWithContentsOfFile:path
                                                  encoding:NSUTF8StringEncoding
                                                     error:NULL];
    NSMutableArray *data = (NSMutableArray *) [content componentsSeparatedByString:@"\n"];
    int numberofCases = [[data objectAtIndex:0] intValue];
    [data removeObjectAtIndex:0];
    for (int i = 1; i <= numberofCases; i++) {
        //get this case data
        double numberofreflection = 1000000000000.0;
        NSString *infoLine = [data objectAtIndex:0];
        [data removeObjectAtIndex:0];
        
        NSArray *component1 = [[NSMutableArray alloc] initWithCapacity:2]; // 2  5
        component1 = [infoLine componentsSeparatedByString:@" "];
        int A = [[component1 objectAtIndex:0] intValue];
        int B = [[component1 objectAtIndex:1] intValue];
        
        NSString *probLine = [data objectAtIndex:0];
        [data removeObjectAtIndex:0];
        
        NSArray *component2 = [[NSMutableArray alloc] initWithCapacity:A]; // 0.6  0.6
        component2 = [probLine componentsSeparatedByString:@" "]; // in total A 
        
        for (int index = 0; index <= A; index++) {
            double M = 1.0;
            for (int j=0; j < A - index; j++) {
                M = M*[[component2 objectAtIndex:j] doubleValue];
            }
            double result = M*(B-A+1+2*index) + (1-M)*(B-A+1+2*index+B+1);
            if (result < numberofreflection) {
                numberofreflection = result;
            }
        }
        
        double enter = (double)A+(double)B;
        if (enter < numberofreflection) {
            numberofreflection = enter;
        }
        
    
        result = [NSString stringWithFormat:@"%@Case #%d: %f\n", result, i, numberofreflection];
    }
    
    
    
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    NSString *documentsDirectory = [paths objectAtIndex:0];
    NSString *filePath = [documentsDirectory stringByAppendingPathComponent:@"question1.txt"];
    
    [result writeToFile:filePath atomically:TRUE encoding:NSUTF8StringEncoding error:NULL];
                    

}


@end
