GotoHome(){
	lr_start_transaction("GotoHome");

		web_set_sockets_option("SSL_VERSION", "AUTO");
	
		web_add_auto_header("Sec-Fetch-Dest", 
			"document");
	
		web_add_auto_header("Sec-Fetch-Site", 
			"none");
	
		web_add_auto_header("Sec-Fetch-Mode", 
			"navigate");
	
		web_add_auto_header("DNT", 
			"1");
	
		web_add_auto_header("Sec-Fetch-User", 
			"?1");
	
		web_add_auto_header("Upgrade-Insecure-Requests", 
			"1");
		
		web_reg_find("Fail=NotFound",
			"Text=Welcome to the Web Tours site.",
			LAST);

		web_reg_save_param("userSession",
			"LB=name=\"userSession\" value=\"",
			"RB=\"/>",
			LAST);

		web_url("WebTours", 
			"URL=http://localhost:1080/WebTours/", 
			"TargetFrame=", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=", 
			"Snapshot=t7.inf", 
			"Mode=HTML", 
			LAST);

	lr_end_transaction("GotoHome",LR_AUTO);
}

Login(){
	lr_start_transaction("Login");

		web_revert_auto_header("Sec-Fetch-User");

		web_add_auto_header("Sec-Fetch-Dest", 
			"frame");

		web_revert_auto_header("Upgrade-Insecure-Requests");

		web_add_header("Origin", 
			"http://localhost:1080");

		web_add_auto_header("Sec-Fetch-Site", 
			"same-origin");
		
		web_reg_find("Fail=NotFound",
			"Text=Welcome, <b>{login}</b>, to the Web Tours reservation pages",
			LAST);

		web_submit_data("login.pl", 
			"Action=http://localhost:1080/cgi-bin/login.pl", 
			"Method=POST", 
			"TargetFrame=body", 
			"RecContentType=text/html", 
			"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home", 
			"Snapshot=t8.inf", 
			"Mode=HTML", 
			ITEMDATA, 
			"Name=userSession", "Value={userSession}", ENDITEM, 
			"Name=username", "Value={login}", ENDITEM, 
			"Name=password", "Value={password}", ENDITEM, 
			"Name=login.x", "Value=34", ENDITEM, 
			"Name=login.y", "Value=6", ENDITEM, 
			"Name=JSFormSubmit", "Value=off", ENDITEM, 
			LAST);

	lr_end_transaction("Login",LR_AUTO);
}

GotoFindTicket(){
	lr_start_transaction("GotoFindTicket");

		web_add_auto_header("Sec-Fetch-User", 
			"?1");
	
		web_add_auto_header("Upgrade-Insecure-Requests", 
			"1");
		
		web_reg_find("Fail=NotFound",
			"Text=Find Flight",
			LAST);
	
		web_url("Search Flights Button", 
			"URL=http://localhost:1080/cgi-bin/welcome.pl?page=search", 
			"TargetFrame=body", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
			"Snapshot=t9.inf", 
			"Mode=HTML", 
			LAST);

	lr_end_transaction("GotoFindTicket",LR_AUTO);
}

FindTicket(){
	lr_start_transaction("FindTicket");
	
		web_add_auto_header("Origin", 
			"http://localhost:1080");
		
		web_reg_save_param("outboundFlight",
			"LB= name=\"outboundFlight\" value=\"",
			"RB=\"",
			LAST);
		
		web_reg_find("Fail=NotFound",
			"Text=Flight departing from <B>{CityDepart}</B> to <B>{CityArrive}</B>",
			LAST);
	
		web_submit_data("reservations.pl", 
			"Action=http://localhost:1080/cgi-bin/reservations.pl", 
			"Method=POST", 
			"TargetFrame=", 
			"RecContentType=text/html", 
			"Referer=http://localhost:1080/cgi-bin/reservations.pl?page=welcome", 
			"Snapshot=t10.inf", 
			"Mode=HTML", 
			ITEMDATA, 
			"Name=advanceDiscount", "Value=0", ENDITEM, 
			"Name=depart", "Value={CityDepart}", ENDITEM, 
			"Name=departDate", "Value={DateDepart}", ENDITEM, 
			"Name=arrive", "Value={CityArrive}", ENDITEM, 
			"Name=returnDate", "Value={DateArrive}", ENDITEM, 
			"Name=numPassengers", "Value=1", ENDITEM, 
			"Name=seatPref", "Value={SeatPref}", ENDITEM, 
			"Name=seatType", "Value={SeatType}", ENDITEM, 
			"Name=findFlights.x", "Value=22", ENDITEM, 
			"Name=findFlights.y", "Value=12", ENDITEM, 
			"Name=.cgifields", "Value=roundtrip", ENDITEM, 
			"Name=.cgifields", "Value=seatType", ENDITEM, 
			"Name=.cgifields", "Value=seatPref", ENDITEM, 
			LAST);
	
		lr_end_transaction("FindTicket",LR_AUTO);
}
	
ChooseTicket(){
	lr_start_transaction("ChooseTicket");
		
		web_reg_find("Fail=NotFound",
			"Text=Flight Reservation",
			LAST);

		web_submit_data("reservations.pl_2", 
			"Action=http://localhost:1080/cgi-bin/reservations.pl", 
			"Method=POST", 
			"TargetFrame=", 
			"RecContentType=text/html", 
			"Referer=http://localhost:1080/cgi-bin/reservations.pl", 
			"Snapshot=t11.inf", 
			"Mode=HTML", 
			ITEMDATA, 
			"Name=outboundFlight", "Value={outboundFlight}", ENDITEM, 
			"Name=numPassengers", "Value=1", ENDITEM, 
			"Name=advanceDiscount", "Value=0", ENDITEM, 
			"Name=seatType", "Value={SeatType}", ENDITEM, 
			"Name=seatPref", "Value={SeatPref}", ENDITEM, 
			"Name=reserveFlights.x", "Value=74", ENDITEM, 
			"Name=reserveFlights.y", "Value=5", ENDITEM, 
			LAST);
	
		lr_end_transaction("ChooseTicket",LR_AUTO);
}

LogOut(){
	lr_start_transaction("LogOut");

		web_revert_auto_header("Origin");
	
		web_revert_auto_header("Sec-Fetch-User");
		
		web_reg_find("Fail=NotFound",
			"Text=Web Tours Navigation Bar",
			LAST);
	
		web_url("SignOff Button", 
			"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
			"TargetFrame=body", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=flights", 
			"Snapshot=t12.inf", 
			"Mode=HTML", 
			LAST);

	lr_end_transaction("LogOut",LR_AUTO);
}

CheckTickets(){
	lr_start_transaction("CheckTickets");

		web_add_header("Sec-Fetch-User", 
			"?1");
	
		web_add_header("Upgrade-Insecure-Requests", 
			"1");
		
		web_reg_find("Fail=NotFound",
			"Text=Itinerary",
			LAST);
	
		web_url("Itinerary Button", 
			"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
			"TargetFrame=body", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
			"Snapshot=t3.inf", 
			"Mode=HTML", 
			LAST);
	
	lr_end_transaction("CheckTickets",LR_AUTO);
}
