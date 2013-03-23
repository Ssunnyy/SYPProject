//
//  YPStyledTableViewCell.h
//  SYPProject
//
//  Created by sunyuping on 12-11-14.
//
//

#import <UIKit/UIKit.h>
// available selection colors
typedef enum
{
    StyledTableViewCellSelectionStyleDefault = 0,
    StyledTableViewCellSelectionStyleCyan = 1,
    StyledTableViewCellSelectionStyleGreen = 2,
    StyledTableViewCellSelectionStyleYellow = 3,
    StyledTableViewCellSelectionStylePurple = 4,
} StyledTableViewCellSelectionStyle;

typedef enum
{
    StyledTableViewCellSelectionGradientDirectionVertical = 0,
    StyledTableViewCellSelectionGradientDirectionHorizontal = 1,
    StyledTableViewCellSelectionGradientDirectionDiagonalTopLeftToBottomRight = 2,
    StyledTableViewCellSelectionGradientDirectionDiagonalBottomLeftToTopRight = 3,
} StyledTableViewCellSelectionGradientDirection;

// background view
// use to draw separator line
@interface StyledTableViewCellBackgroundView : UIView
@property (nonatomic, strong) UIColor *separatorColor;
@property (nonatomic, assign) int dashWidth, dashGap, dashStroke;
@end

// selected background view
// subclass of background view, set the colors
@interface StyledTableViewCellSelectedBackgroundView : StyledTableViewCellBackgroundView
@property (nonatomic, strong) NSArray *selectedBackgroundGradientColors;
@property (nonatomic, assign) StyledTableViewCellSelectionGradientDirection gradientDirection;
@end


@interface YPStyledTableViewCell : UITableViewCell
// set the separator line property
@property (nonatomic, assign) int dashWidth;
@property (nonatomic, assign) int dashGap;
@property (nonatomic, assign) int dashStroke;
- (void)setDashWidth:(int)dashWidth dashGap:(int)dashGap dashStroke:(int)dashStroke;
- (void)setSeparatorColor:(UIColor*)separatorColor;

// set the selected background color by providing an array of colors
// requires a list of CGColor
- (void)setSelectedBackgroundViewGradientColors:(NSArray*)colors;
// set the selected background color gradient direction
- (void)setSelectionGradientDirection:(StyledTableViewCellSelectionGradientDirection)direction;

// set the selected background color using style
@property (nonatomic, assign, setter = setStyledTableViewCellSelectionStyle:) StyledTableViewCellSelectionStyle styledTableViewCellSelectionStyle;
@end
