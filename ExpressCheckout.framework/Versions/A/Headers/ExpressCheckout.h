//
//  ExpressCheckout.h
//  ExpressCheckout
//
//  Created by Sachin Sharma on 28/04/16.
//  Copyright © 2016 Juspay Technologies Pvt Ltd. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <JuspaySafeBrowser/JuspaySafeBrowser.h>
#import "CardValidator.h"

typedef enum {
    DEFAULT_AUTHENTICATION,
    ATMPIN_AUTHENTICATION
} CardAuthenticationType;

typedef void(^Callback)(id data, NSError * error);

@interface ExpressCheckout : UIView

@property (nonatomic, strong) JuspaySafeBrowser *browser;
@property (nonatomic) Boolean shouldLoadEndURL;
@property (nonatomic) Boolean shouldNotPopOnEndURL;
@property (nonatomic) Boolean shouldNotPopAfterPayment;
@property (nonatomic, strong) NSArray *cookies;
@property (nonatomic, strong) UIView *customActivityIndicator;
@property (nonatomic, strong) NSArray *confirmationAlertContents;

- (id)initWithClientKey:(NSString *)clientKey environment:(Environment)environment __attribute__ ((deprecated));

- (void)backButtonPressed;
- (BOOL)isControllerAllowedToPop;

+ (void)performLogout;

- (void)environment:(Environment)environment merchantId:(NSString*)merchantId orderId:(NSString*)orderID endUrlRegexes:(NSArray*)endUrlRegexes;

- (void)environment:(Environment)environment merchantId:(NSString*)merchantId orderId:(NSString*)orderId endUrlRegexes:(NSArray*)endUrlRegexes customParameters:(NSDictionary<NSString*,NSString*> *)parameters;

- (void)getMerchantPaymentConfigEnvironment:(Environment)environment merchantId:(NSString*)merchantId orderId:(NSString*)orderId callback:(Callback)callback;

//Iframe based Payment

- (void)environment:(Environment)environment merchantId:(NSString*)merchantId orderId:(NSString*)orderID instrumentOptions:(NSArray*)intrumentOptions endUrlRegexes:(NSArray*)endUrlRegexes;

- (void)environment:(Environment)environment merchantId:(NSString*)merchantId orderId:(NSString*)orderID instrumentOptions:(NSArray*)intrumentOptions endUrlRegexes:(NSArray*)endUrlRegexes customParameters:(NSDictionary<NSString*,NSString*> *)parameters;

//Wallet Payment
- (void)environment:(Environment)environment merchantId:(NSString*)merchantId orderId:(NSString*)orderID wallet:(NSString*)wallet endUrlRegexes:(NSArray*)endUrlRegexes;

//Netbanking Payment
- (void)environment:(Environment)environment merchantId:(NSString *)merchantId orderId:(NSString *)orderID netbankingBank:(NSString *)bank  endUrlRegexes:(NSArray *)endUrlRegexes;

//Card Payment
- (void)environment:(Environment)environment merchantId:(NSString *)merchantId orderId:(NSString *)orderID cardNumber:(NSString *)number cardExpiryYear:(NSString*)year cardExpiryMonth:(NSString*)month cardSecurityCode:(NSString*)securityCode nameOnCard:(NSString*)name authType:(CardAuthenticationType)authType saveToLocker:(Boolean)saveToLocker endUrlRegexes:(NSArray *)endUrlRegexes;

//Saved Card Payment
- (void)environment:(Environment)environment merchantId:(NSString *)merchantId orderId:(NSString *)orderID savedCardToken:(NSString *)token cardSecurityCode:(NSString*)securityCode authType:(CardAuthenticationType)authType endUrlRegexes:(NSArray *)endUrlRegexes;

//UPI Payment
- (void)environment:(Environment)environment merchantId:(NSString *)merchantId orderId:(NSString *)orderID upiVpa:(NSString *)upiVpa redirectAfterPayment:(Boolean)redirect endUrlRegexes:(NSArray *)endUrlRegexes;

//Load url directly in browser 
- (void)loadUrl:(NSString*)url merchantId:(NSString*)merchantId orderId:(NSString*)orderId endUrlRegexes:(NSArray *)endUrlRegexes;

//Tokenize Cards
- (void)tokenizeEnvironment:(Environment)environment merchantId:(NSString *)merchantId cardNumber:(NSString *)number cardExpiryYear:(NSString *)year cardExpiryMonth:(NSString*)month cardSecurityCode:(NSString*)securityCode nameOnCard:(NSString*)name callback:(JPBlock)block;

//Tokenize Saved Cards
- (void)tokenizeEnvironment:(Environment)environment merchantId:(NSString *)merchantId cardSecurityCode:(NSString*)securityCode storedCardToken:(NSString*)storedToken callback:(JPBlock)block;

- (void)startPaymentInView:(UIView*)view callback:(JPBlock)block;
- (Environment)environmentEnumFromString:(NSString*)input;

@end
