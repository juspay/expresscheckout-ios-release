//
//  ExpressCheckout.h
//  ExpressCheckout
//
//  Created by Sachin Sharma on 28/04/16.
//  Copyright © 2016 Juspay Technologies Pvt Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <JuspaySafeBrowser/JuspaySafeBrowser.h>
#import "Environments.h"

@interface ExpressCheckout : UIView

- (void)environment:(Environment)environment merchantId:(NSString*)merchantId orderId:(NSString*)orderId endUrlRegexes:(NSArray*)endUrlRegexes;

//Iframe based Payment
/**
 Setup's IFrame based payment.

 @param environment Environment for which Payment is starting.
 @param merchantId Merchant id provided by juspay.
 @param orderID Order id for the transaction.
 @param intrumentOptions Instument options can be a set of instuments to start transaction with. ex :Cards, NB,etc. Default is ALL.
 @param endUrlRegexes Endurls setup while order create or default endurl setup in dashboard.
 */
- (void)environment:(Environment)environment merchantId:(NSString*)merchantId orderId:(NSString*)orderID instrumentOptions:(NSArray*)intrumentOptions endUrlRegexes:(NSArray*)endUrlRegexes;

//Wallet Payment
/**
 Setup's Wallet based payment.

 @param environment Environment for which Payment is starting.
 @param merchantId Merchant id provided by juspay.
 @param orderID Order id for the transaction.
 @param wallet Wallet for which to start payment . ex: Paytm, Freecharge, etc
 @param endUrlRegexes Endurls setup while order create or default endurl setup in dashboard.
 */
- (void)environment:(Environment)environment merchantId:(NSString*)merchantId orderId:(NSString*)orderID wallet:(NSString*)wallet endUrlRegexes:(NSArray*)endUrlRegexes;

//Netbanking Payment
/**
 Setup's Wallet based payment.

 @param environment Environment for which Payment is starting.
 @param merchantId Merchant id provided by juspay.
 @param orderID Order id for the transaction.
 @param bank Bank for which transaction is to be started.
 @param endUrlRegexes Endurls setup while order create or default endurl setup in dashboard.
 */
- (void)environment:(Environment)environment merchantId:(NSString *)merchantId orderId:(NSString *)orderID netbankingBank:(NSString *)bank  endUrlRegexes:(NSArray *)endUrlRegexes;

//Card Payment
/**
 Setup's Card based payment.

 @param environment Environment for which Payment is starting.
 @param merchantId Merchant id provided by juspay.
 @param orderID Order id for the transaction.
 @param number Card Number
 @param year Card Expiry Year
 @param month Card Expiry Month
 @param securityCode Card Expiry Security Code (CVV|CVV2)
 @param name Name on the card
 @param endUrlRegexes Endurls setup while order create or default endurl setup in dashboard.
 */
- (void)environment:(Environment)environment merchantId:(NSString *)merchantId orderId:(NSString *)orderID cardNumber:(NSString *)number cardExpiryYear:(NSString*)year cardExpiryMonth:(NSString*)month cardSecurityCode:(NSString*)securityCode nameOnCard:(NSString*)name endUrlRegexes:(NSArray *)endUrlRegexes;

/**
 Starts the payment process

 @param view View in which payment should start.
 @param block Callback block triggered after transaction is complete or cancelled by user.
 */
- (void)startPaymentInView:(UIView*)view callback:(JPBlock)block;
- (Environment)environmentEnumFromString:(NSString*)input;

@end
