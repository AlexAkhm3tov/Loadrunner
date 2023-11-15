Action()
{
	
	lr_start_transaction("UC6_RegAllUser");
	
		GotoHome();
		
		lr_think_time(4);
	
		lr_start_transaction("SignUP");
	
			web_add_auto_header("Sec-Fetch-Dest", 
				"frame");
		
			web_revert_auto_header("Sec-Fetch-User");
		
			web_revert_auto_header("Upgrade-Insecure-Requests");
		
			web_add_auto_header("Sec-Fetch-Site", 
				"same-origin");
			
			web_reg_find("Fail=NotFound",
				"Text=First time registering",
				LAST);
			
			web_url("sign up now", 
				"URL=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
				"TargetFrame=body", 
				"Resource=0", 
				"RecContentType=text/html", 
				"Referer=http://localhost:1080/WebTours/home.html", 
				"Snapshot=t2.inf", 
				"Mode=HTML", 
				LAST);
	
		lr_end_transaction("SignUP",LR_AUTO);
		
		lr_think_time(20);
	
		lr_start_transaction("Registration");
	
			web_add_header("Origin", 
				"http://localhost:1080");
		
			web_add_auto_header("Sec-Fetch-User", 
				"?1");
		
			web_add_auto_header("Upgrade-Insecure-Requests", 
				"1");
		
			web_reg_find("Fail=NotFound",
				"Text=welcome to the Web Tours family",
				LAST);
		
			web_submit_data("login.pl", 
				"Action=http://localhost:1080/cgi-bin/login.pl", 
				"Method=POST", 
				"TargetFrame=info", 
				"RecContentType=text/html", 
				"Referer=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
				"Snapshot=t3.inf", 
				"Mode=HTML", 
				ITEMDATA, 
				"Name=username", "Value={login}", ENDITEM, 
				"Name=password", "Value={password}", ENDITEM, 
				"Name=passwordConfirm", "Value={password}", ENDITEM, 
				"Name=firstName", "Value={fname}", ENDITEM, 
				"Name=lastName", "Value={lname}", ENDITEM, 
				"Name=address1", "Value={street}", ENDITEM, 
				"Name=address2", "Value={city}", ENDITEM, 
				"Name=register.x", "Value=84", ENDITEM, 
				"Name=register.y", "Value=13", ENDITEM, 
				LAST);
		
		lr_end_transaction("Registration",LR_AUTO);
	
		lr_start_transaction("Continue");
	
			web_reg_find("Text/IC=Welcome, <b>{login}</b>, to the Web Tours reservation pages.",
			LAST);

			web_url("button_next.gif", 
			"URL=http://localhost:1080/cgi-bin/welcome.pl?page=menus", 
			"TargetFrame=body", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=http://localhost:1080/cgi-bin/login.pl", 
			"Snapshot=t4.inf", 
			"Mode=HTML", 
			LAST);

		lr_end_transaction("Continue",LR_AUTO);
		
		LogOut();
		
	lr_end_transaction("UC6_RegAllUser",LR_AUTO);

	return 0;
}