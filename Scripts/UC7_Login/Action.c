Action() 
{

	lr_start_transaction("UC7_Login");

		GotoHome();
		
		lr_think_time(5);
	
		Login();
		
		lr_think_time(5);
	
		LogOut();

	lr_end_transaction("UC7_Login",LR_AUTO);
		
	return 0;
}