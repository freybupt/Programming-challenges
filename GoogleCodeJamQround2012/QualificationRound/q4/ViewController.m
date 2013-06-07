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

    NSString* path = [[NSBundle mainBundle] pathForResource:@"D-small-attempt0" 
                                                     ofType:@"in"];
    NSString* content = [NSString stringWithContentsOfFile:path
                                                  encoding:NSUTF8StringEncoding
                                                     error:NULL];
    NSMutableArray *data = (NSMutableArray *) [content componentsSeparatedByString:@"\n"];
    int numberofCases = [[data objectAtIndex:0] intValue];
    [data removeObjectAtIndex:0];
    for (int i = 1; i <= numberofCases; i++) {
        //get this case data
        int numberofreflection = 0;
        NSString *infoLine = [data objectAtIndex:0];
        [data removeObjectAtIndex:0];
        int rowNumber = [[[infoLine componentsSeparatedByString:@" "] objectAtIndex:0] intValue];
        int colNumber = [[[infoLine componentsSeparatedByString:@" "] objectAtIndex:1] intValue];
        int visibleDistance = [[[infoLine componentsSeparatedByString:@" "] objectAtIndex:2] intValue];
        NSMutableArray *mirrorData = [[NSMutableArray alloc] initWithCapacity:rowNumber];
        
        for (int j = 0; j < rowNumber; j++) {
            [mirrorData addObject:[data objectAtIndex:0]];
            [data removeObjectAtIndex:0];
        }
        
        //create all objects in mirror room
        NSMutableArray *mirrorObjects = [[NSMutableArray alloc] init];
        HumanObject *human = [[HumanObject alloc] init];
       
        for (int y = 0; y < rowNumber; y++) {
            NSString *thisRow = [mirrorData objectAtIndex:y];
            int x = 0;
            while([thisRow length] > 0) {
                NSString *thisCell = [thisRow substringToIndex:1];
                thisRow  = [thisRow substringFromIndex:1];
                if ([thisCell isEqualToString:@"#"]) {
                    MirrorObject *oneMirror = [[MirrorObject alloc] init];
                    oneMirror.xIndex = x;
                    oneMirror.yIndex = y;
                    [mirrorObjects addObject:oneMirror];
                    
                }
                else if([thisCell isEqualToString:@"X"]){
                    human.xIndex = x;
                    human.yIndex = y;
                }
                x++;
            }

        }
        
        for (MirrorObject *thisMirror in mirrorObjects) {
            double distance = sqrt(abs(thisMirror.xIndex - human.xIndex)*abs(thisMirror.xIndex - human.xIndex) + abs(thisMirror.yIndex - human.yIndex)*abs(thisMirror.yIndex - human.yIndex));
            
            if ((distance-0.5)*2 <= visibleDistance) {
                numberofreflection = numberofreflection + visibleDistance/((distance-0.5)*2);
            }

            
//            MirrorObject *neiborMirror1 = [[MirrorObject alloc] init];
//            MirrorObject *neiborMirror2 = [[MirrorObject alloc] init];
//            if (thisMirror.xIndex > 0 && thisMirror.yIndex > 0 && thisMirror.xIndex < colNumber && thisMirror.yIndex < rowNumber) {
//                
//                if (human.xIndex < thisMirror.xIndex && human.yIndex < thisMirror.yIndex) {
//                    neiborMirror1.xIndex = thisMirror.xIndex;
//                    neiborMirror1.yIndex = thisMirror.yIndex -1;
//                    neiborMirror2.xIndex = thisMirror.xIndex -1;
//                    neiborMirror2.yIndex = thisMirror.yIndex;
//                }
//                else if(human.xIndex > thisMirror.xIndex && human.yIndex < thisMirror.yIndex){
//                    neiborMirror1.xIndex = thisMirror.xIndex;
//                    neiborMirror1.yIndex = thisMirror.yIndex +1;
//                    neiborMirror2.xIndex = thisMirror.xIndex -1;
//                    neiborMirror2.yIndex = thisMirror.yIndex;
//                }
//                else if(human.xIndex < thisMirror.xIndex && human.yIndex > thisMirror.yIndex){
//                    neiborMirror1.xIndex = thisMirror.xIndex;
//                    neiborMirror1.yIndex = thisMirror.yIndex +1;
//                    neiborMirror2.xIndex = thisMirror.xIndex -1;
//                    neiborMirror2.yIndex = thisMirror.yIndex;
//                }
//                else if(human.xIndex > thisMirror.xIndex && human.yIndex > thisMirror.yIndex){
//                    neiborMirror1.xIndex = thisMirror.xIndex;
//                    neiborMirror1.yIndex = thisMirror.yIndex +1;
//                    neiborMirror2.xIndex = thisMirror.xIndex +1;
//                    neiborMirror2.yIndex = thisMirror.yIndex;
//                }
//            
//            
//                for (MirrorObject *compareMirror in mirrorObjects) {
//                    thisMirror.isIsolate = YES;
//                    if (compareMirror.xIndex == neiborMirror1.xIndex && compareMirror.yIndex == neiborMirror1.yIndex) {
//                        thisMirror.isIsolate = NO;
//                    }
//                    if (compareMirror.xIndex == neiborMirror2.xIndex && compareMirror.yIndex == neiborMirror2.yIndex) {
//                        thisMirror.isIsolate = NO;
//                    }
//                    
//                    if ((distance-0.5)*2 <= visibleDistance && !thisMirror.isIsolate) {
//                        numberofreflection++;
//                    }
//                    
//                }
//            }
//            else{
//                if ((distance-0.5)*2 <= visibleDistance) {
//                    numberofreflection++;
//                }
//            }
            
        }
    
        result = [NSString stringWithFormat:@"%@Case #%d: %d\n", result, i, numberofreflection];
    }
    
    
    
    NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    NSString *documentsDirectory = [paths objectAtIndex:0];
    NSString *filePath = [documentsDirectory stringByAppendingPathComponent:@"Question4.txt"];
    
    [result writeToFile:filePath atomically:TRUE encoding:NSUTF8StringEncoding error:NULL];
                    

}


@end
