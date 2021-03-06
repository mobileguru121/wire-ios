//
// Wire
// Copyright (C) 2016 Wire Swiss GmbH
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see http://www.gnu.org/licenses/.
//


#import "ConversationContentViewControllerDelegate.h"

@class ZMConversation;
@class ZClientViewController;
@class ConversationCallController;

@protocol ZMUserSessionInterface;

NS_ASSUME_NONNULL_BEGIN

@interface ConversationViewController : UIViewController

@property (nonatomic, weak, nullable) ZClientViewController *zClientViewController;
@property (nonatomic, null_unspecified) ZMConversation *conversation;
@property (nonatomic, null_unspecified) id<ZMUserSessionInterface> session;
@property (nonatomic, nullable) id<ZMConversationMessage> visibleMessage;
@property (nonatomic, getter=isFocused) BOOL focused;
@property (nonatomic, readonly) ConversationCallController *startCallController;

- (void)scrollToMessage:(id<ZMConversationMessage>)message;

@end

NS_ASSUME_NONNULL_END
