Action()
{

	lr_start_transaction("UC2_BuyTicket");

		GotoHome();
		
		lr_think_time(7);
	
		Login();
		
		lr_think_time(13);
		
		GotoFindTicket();
		
		lr_think_time(5);
	
		FindTicket();
	
		lr_think_time(11);
	
		ChooseTicket();
		
		lr_think_time(8);
		
		lr_start_transaction("BuyTicket");
		
			web_revert_auto_header("Origin");
		
			web_revert_auto_header("Sec-Fetch-User");
		
			web_revert_auto_header("Upgrade-Insecure-Requests");
		
			web_add_header("Origin", 
				"http://localhost:1080");
			
			web_reg_find("Fail=NotFound",
				"Text=Invoice",
				LAST);
		
			web_submit_data("reservations.pl_3", 
				"Action=http://localhost:1080/cgi-bin/reservations.pl", 
				"Method=POST", 
				"TargetFrame=", 
				"RecContentType=text/html", 
				"Referer=http://localhost:1080/cgi-bin/reservations.pl", 
				"Snapshot=t6.inf", 
				"Mode=HTML", 
				ITEMDATA, 
				"Name=firstName", "Value={fname}", ENDITEM, 
				"Name=lastName", "Value={lname}", ENDITEM, 
				"Name=address1", "Value={street}", ENDITEM, 
				"Name=address2", "Value={city}", ENDITEM, 
				"Name=pass1", "Value={pasname}", ENDITEM, 
				"Name=creditCard", "Value={card}", ENDITEM, 
				"Name=expDate", "Value={expdate}", ENDITEM, 
				"Name=oldCCOption", "Value=", ENDITEM, 
				"Name=numPassengers", "Value=1", ENDITEM, 
				"Name=seatType", "Value={SeatType}", ENDITEM, 
				"Name=seatPref", "Value={SeatPref}", ENDITEM, 
				"Name=outboundFlight", "Value={outboundFlight}", ENDITEM, 
				"Name=advanceDiscount", "Value=0", ENDITEM, 
				"Name=returnFlight", "Value=", ENDITEM, 
				"Name=JSFormSubmit", "Value=off", ENDITEM, 
				"Name=buyFlights.x", "Value=52", ENDITEM, 
				"Name=buyFlights.y", "Value=9", ENDITEM, 
				"Name=.cgifields", "Value=saveCC", ENDITEM, 
				LAST);
	
		lr_end_transaction("BuyTicket",LR_AUTO);
	
		lr_think_time(9);
		
		LogOut();

	lr_end_transaction("UC2_BuyTicket",LR_AUTO);

	return 0;
}