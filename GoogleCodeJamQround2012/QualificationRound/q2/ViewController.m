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
	//question 1
//    letterDictionary = [[NSDictionary alloc] initWithObjectsAndKeys:\
//                        @"a", @"y",\
//                        @"b", @"n",                                           
//                        @"c", @"f",\
//                        @"d", @"i",\
//                        @"e", @"c",\
//                        @"f", @"w",\
//                        @"g", @"l",\
//                        @"h", @"b",\
//                        @"i", @"k",\
//                        @"j", @"u",\
//                        @"k", @"o",\
//                        @"l", @"m",\
//                        @"m", @"x",\
//                        @"n", @"s",\
//                        @"o", @"e",\
//                        @"p", @"v",\
//                        @"q", @"z",\
//                        @"r", @"p",\
//                        @"s", @"d",\
//                        @"t", @"r",\
//                        @"u", @"j",\
//                        @"v", @"g",\
//                        @"w", @"t",\
//                        @"x", @"h",\
//                        @"y", @"a",\
//                        @"z", @"q",\
//                        @" ", @" ",\
//                        nil];
//    
//    NSString* path = [[NSBundle mainBundle] pathForResource:@"A-small-attempt2" 
//                                                     ofType:@"in"];
//    NSString* content = [NSString stringWithContentsOfFile:path
//                                                  encoding:NSUTF8StringEncoding
//                                                     error:NULL];
//    NSString *result = @"";
//    int lineNumber = 0;
//    while([content length] > 0) {
//        
//        NSString *letter = [content substringToIndex:1];
//        content = [content substringFromIndex:1];
//        if ([letter isEqualToString:@"\n"] && [content length] > 0) {
//            lineNumber++;
//            if (lineNumber > 1) {
//                result = [NSString stringWithFormat:@"%@%@Case #%d: ", result, letter, lineNumber];
//            }
//            else{
//                result = [NSString stringWithFormat:@"%@Case #%d: ", result, lineNumber];
//            }
//            
//        }
//        else if ([letterDictionary objectForKey:letter]) {
//            result = [NSString stringWithFormat:@"%@%@", result, [letterDictionary objectForKey:letter]];
//        }
//        else if(lineNumber > 0){
//            result = [NSString stringWithFormat:@"%@%@", result, letter];
//        }
//        
//        
//    }
//    
    
    //question 2
    NSString* path = [[NSBundle mainBundle] pathForResource:@"B-large" 
                                                     ofType:@"in"];
    NSString* content = [NSString stringWithContentsOfFile:path
                                                  encoding:NSUTF8StringEncoding
                                                     error:NULL];
    NSArray *cases = [content componentsSeparatedByString:@"\n"];
    NSString *result = @"";
    int T = [[cases objectAtIndex:0] intValue];
    for (int caseIndex = 1; caseIndex<= T; caseIndex++) {
        NSString *thisCase = [cases objectAtIndex:caseIndex];
        NSArray *data = [thisCase componentsSeparatedByString:@" "];
        int N = [[data objectAtIndex:0] intValue];
        int S = [[data objectAtIndex:1] intValue];
        int p = [[data objectAtIndex:2] intValue];
        int numberofgooddancer = 0;
        NSMutableArray *scores = [[NSMutableArray alloc] initWithCapacity:N];
        for (int j = 0; j < N; j++) {
            [scores addObject:[NSNumber numberWithInt:[[data objectAtIndex:3+j] intValue]]];
        }
        
        //compute the number of good dancer
        int scoreUpperBound = 3*p -2;
        int scoreLowerBound = 3*p -4;
        int numberofOkdancers = 0;
        for (int j = 0; j < [scores count]; j++) {
            int oneScore = [[scores objectAtIndex:j] intValue];
            if (oneScore >= scoreUpperBound) {
                numberofgooddancer++;
            }
            else if(oneScore >= scoreLowerBound && oneScore > 0){
                numberofOkdancers++;
            }
        }
        
        if (numberofOkdancers > S) {
            numberofgooddancer = numberofgooddancer + S;
        }
        else{
            numberofgooddancer = numberofgooddancer + numberofOkdancers;
        }
        
        result = [NSString stringWithFormat:@"%@Case #%d: %d\n", result, caseIndex, numberofgooddancer];
    }
    
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    NSString *documentsDirectory = [paths objectAtIndex:0];
    NSString *filePath = [documentsDirectory stringByAppendingPathComponent:@"Question2_large.txt"];
    
    [result writeToFile:filePath atomically:TRUE encoding:NSUTF8StringEncoding error:NULL];
                    

}


@end
