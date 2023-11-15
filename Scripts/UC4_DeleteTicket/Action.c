Action()
{
	int i;
	int j;
	int k;
	int rndNumber;
	int checkboxMas[20];
	int checkboxMasNew[20];
	int checkboxRand;
	int sizeCheckbox;
	int checkboxValue;
	
	lr_start_transaction("UC4_DeleteTicket");
	
		GotoHome();
		
		lr_think_time(7);
	
		Login();

		lr_think_time(7);

		web_reg_find("SaveCount=NoBooking",
			"Text/IC=<H3>No flights have been reserved.</H3>",
			LAST);
	 
		web_reg_save_param("flightID",
			 "LB/IC=flightID\" value=\"",
			 "RB/IC=\"",
			 "Ord=ALL",
			 "NotFound=WARNING",
			 LAST);
	 
		web_reg_save_param("checkbox",
			 "LB/IC=checkbox\" name=\"",
			 "RB/IC=\"",
			 "Ord=ALL",
			 "NotFound=WARNING",
			 LAST);

		CheckTickets();
		
		rndNumber = atoi((lr_eval_string("{rndNumber}")));
		
		sizeCheckbox = atoi(lr_eval_string("{checkbox_count}"));
		
		if (sizeCheckbox < rndNumber){
			rndNumber = 1;
		}
	
		lr_think_time(13);
	                  
		if (atoi(lr_eval_string("{NoBooking}")) == 1) {
	  
			LogOut();
	     
	    }
	 
		else {
			for(j = 0; j < sizeCheckbox; j++){
				checkboxMas[j] = (j + 1);
			}
     
			lr_start_transaction("DeleteTicket");
			
			if (rndNumber == 1){
				checkboxRand = rand() % sizeCheckbox;
				checkboxValue = checkboxMas[checkboxRand];
				lr_save_int(checkboxValue, "rndCheckbox1");
				lr_save_string(lr_paramarr_idx("flightID", checkboxValue), "rndFlightID1");
				
				web_reg_find("Fail=Found",
				  "Text/IC={rndFlightID1}",
				  LAST);
				
				web_submit_form("itinerary.pl", 
					"Snapshot=t4.inf", 
					ITEMDATA, 
					"Name={rndCheckbox1}", "Value=on", ENDITEM,
					"Name=removeFlights.x", "Value=55", ENDITEM,
					"Name=removeFlights.y", "Value=9", ENDITEM, 
					LAST);
			} else if (rndNumber == 2){
				checkboxRand = rand() % sizeCheckbox;
				checkboxValue = checkboxMas[checkboxRand];
				lr_save_int(checkboxValue, "rndCheckbox1");
				lr_save_string(lr_paramarr_idx("flightID", checkboxValue), "rndFlightID1");
				               
				for (k = 0; k < sizeCheckbox; k++){
					if(k != (checkboxRand - 1)){
				        checkboxMasNew[k] = checkboxMas[k];
	               	}
				}
				checkboxRand = rand() % (sizeCheckbox - 1);
				checkboxValue = checkboxMasNew[checkboxRand];
				lr_save_int(checkboxValue, "rndCheckbox2");
				lr_save_string(lr_paramarr_idx("flightID", checkboxValue), "rndFlightID2");
				
				web_reg_find("Fail=Found",
				  "Text/IC={rndFlightID1}",
				  LAST);
				
				web_reg_find("Fail=Found",
				  "Text/IC={rndFlightID2}",
				  LAST);
				
				web_submit_form("itinerary.pl", 
					"Snapshot=t4.inf", 
					ITEMDATA, 
					"Name={rndCheckbox1}", "Value=on", ENDITEM,
					"Name={rndCheckbox2}", "Value=on", ENDITEM,
					"Name=removeFlights.x", "Value=55", ENDITEM,
					"Name=removeFlights.y", "Value=9", ENDITEM, 
					LAST);
			} else if (rndNumber == 3){
				checkboxRand = rand() % sizeCheckbox;
				checkboxValue = checkboxMas[checkboxRand];
				lr_save_int(checkboxValue, "rndCheckbox1");
				lr_save_string(lr_paramarr_idx("flightID", checkboxValue), "rndFlightID1");
				               
				for (k = 0; k < sizeCheckbox; k++){
					if(k != (checkboxRand - 1)){
				        checkboxMasNew[k] = checkboxMas[k];
	               	}
				}
				
				for (k = 0; k < sizeCheckbox; k++){
				        checkboxMas[k] = checkboxMasNew[k];
				}
				
				checkboxRand = rand() % (sizeCheckbox - 1);
				checkboxValue = checkboxMasNew[checkboxRand];
				lr_save_int(checkboxValue, "rndCheckbox2");
				lr_save_string(lr_paramarr_idx("flightID", checkboxValue), "rndFlightID2");
					
				for (k = 0; k < sizeCheckbox; k++){
					if(k != (checkboxRand - 1)){
				        checkboxMasNew[k] = checkboxMas[k];
	               	}
				}
				checkboxRand = rand() % (sizeCheckbox - 2);
				checkboxValue = checkboxMasNew[checkboxRand];
				lr_save_int(checkboxValue, "rndCheckbox3");
				lr_save_string(lr_paramarr_idx("flightID", checkboxValue), "rndFlightID3");
				
				web_reg_find("Fail=Found",
				  "Text/IC={rndFlightID1}",
				  LAST);
				
				web_reg_find("Fail=Found",
				  "Text/IC={rndFlightID2}",
				  LAST);
				
				web_reg_find("Fail=Found",
				  "Text/IC={rndFlightID3}",
				  LAST);
				
				web_submit_form("itinerary.pl", 
					"Snapshot=t4.inf", 
					ITEMDATA, 
					"Name={rndCheckbox1}", "Value=on", ENDITEM,
					"Name={rndCheckbox2}", "Value=on", ENDITEM,
					"Name={rndCheckbox3}", "Value=on", ENDITEM,
					"Name=removeFlights.x", "Value=55", ENDITEM,
					"Name=removeFlights.y", "Value=9", ENDITEM, 
					LAST);
			}
			
			lr_end_transaction("DeleteTicket",LR_AUTO);
			
		
//			for (i = 0; i < rndNumber; ++i) {
//		
//				lr_save_string(lr_paramarr_random("checkbox"), "rndCheckbox");
//	
//				lr_save_string(lr_paramarr_idx("flightID", atoi(lr_eval_string("rndCheckbox"))), "rndFlightID");
//
//				web_reg_find("Fail=Found",
//				  "Text/IC={rndFlightID}",
//				  LAST);
//	     
//				lr_start_transaction("DeleteTicket");
//				
////					lr_save_string(lr_paramarr_random("checkbox"), "rndCheckbox");
////	
////					lr_save_string(lr_paramarr_idx("flightID", atoi(lr_eval_string("rndCheckbox"))), "rndFlightID");
////	
////					web_reg_find("Fail=Found",
////				  		"Text/IC={rndFlightID}",
////				 	 	LAST);
//					
//				web_submit_form("itinerary.pl", 
//					"Snapshot=t4.inf", 
//					ITEMDATA, 
//					"Name={rndCheckbox}", "Value=on", ENDITEM,
//					"Name=removeFlights.x", "Value=55", ENDITEM,
//					"Name=removeFlights.y", "Value=9", ENDITEM, 
//					LAST);
//				
//				lr_end_transaction("DeleteTicket",LR_AUTO);
//			}
				
		}
		
	lr_end_transaction("UC4_DeleteTicket",LR_AUTO);

	return 0;
}