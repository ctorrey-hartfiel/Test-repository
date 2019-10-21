/* device:       /project/Tera_7 */
/* device model: TERA7 */
/* this file has been generated automatically by vt3 - do not modify! */


#ifndef INCLUDE__VT3_EVENT__HOME_C
#define INCLUDE__VT3_EVENT__HOME_C

#include "vt3_base.h"
#include "vt3_lang.h"
#include "vt3_images.h"
#include "vt3_fonts.h"
#include "vt3_POU_common.h"
#include "vt3_Disp__Home.h"
#include "vt3_Event__Home.h"
#include "vt3_extra.h"
#include "version_vt3_runtime.h"
#include "version_pdfrender.h"

/* timer event handler for screen: /project/Tera_7/Screens/home */
void vt3_event_ind_home(BYTE event)
{
	/* Warning: the code below is generated by vt3.
	 * If you wish to make changes, please use vt3.
	 * 
	 *  node is:    /project/Tera_7/Screens/home
	 * 
	 * Omitted: the list of replaced identifiers is very long
	 */
	{
	
	
	   /*Home Screen Button Logic*/
		 if ((ind_screen_frame_key_F1).eventDown)  
	    {
	        if (SystemOn == 0)
	        {
	            SystemOn = 1;
	        }
	        else
	        {
	            SystemOn = 0;
	        }
	    }
	    else if ((ind_screen_frame_key_F2).eventDown) 
	    {
	        if (AutoMan == 0)
	        {
	            AutoMan = 1;
	            SaveP = (TRUE);
	        }
	        else
	        {
	            AutoMan = 0;
	            SaveP = (TRUE);
	        }
	    }
	    else if (((ind_screen_frame_key_F3).eventDown) &&
	            (SystemOn) &&       
	            (AutoMan == 1))  
	    {
	        if (FanOnMan == 0)
	        {
	            FanOnMan = 1;
	        }
	        else
	        {
	            FanOnMan = 0;
	            AcOnMan = 0;
	            HeatOnMan = 0;
	        }
	    }
	    else if (((ind_screen_frame_key_F4).eventDown) &&
	            (SystemOn) && 
	            (AutoMan == 1)) 
	    {
	        if (AcOnMan == 0)
	        {
	            FanOnMan = 1;
	            AcOnMan = 1;
	            HeatOnMan = 0;
	        }
	        else
	        {
	            AcOnMan = 0;
	        }
	    }
	    else if (((ind_screen_frame_key_F5).eventDown) &&
	                (SystemOn) && 
	                (AutoMan == 1))  
	    {
	        if (HeatOnMan == 0)
	        {
	            FanOnMan = 1;
	            HeatOnMan = 1;
	            AcOnMan = 0;
	        }
	        else
	        {
	            HeatOnMan = 0;
	        }        
	    }
	    else if ((ind_screen_frame_key_F6).eventDown) 
	    {
	        if (InteriorLightsOn == 0)
	        {
	            InteriorLightsOn = 1;
	        }
	        else
	        {
	            InteriorLightsOn = 0;
	        }        
	    }
	    else if ((ind_screen_frame_key_F7).eventDown) 
	    {
	        reqScreen = SCREEN_CAMERA_2;      
	        
	        if (vt3_screen != reqScreen)
	        {
	            vt3_screen = reqScreen;
	        }
	    }
	    else if ((ind_screen_frame_key_F9).eventDown) 
	    {
	        if (StrobeLightsOn == 0)
	        {
	            StrobeLightsOn = 1;
	        }
	        else
	        {
	            StrobeLightsOn = 0;
	        }        
	    }
	     else if ((ind_screen_frame_key_F10).eventDown)  
	    {
	        if (StrobePatternPulse == 0)
	        {
	            StrobePatternPulse = 1;
	        }
	        else
	        {
	            /*Do Nothing */
	        }
	    }
	    else if ((ind_screen_frame_key_F11).eventDown) 
	    {
	        p_Brightness += 100;
	        
	        if (p_Brightness > 1000)
	        {
	            p_Brightness = 1000;
	        }
	        
	        SaveP = (TRUE);
	    }
	    else if ((ind_screen_frame_key_F12).eventDown) 
	    {
	        p_Brightness -= 100;
	        
	        if (p_Brightness < 0)
	        {
	            p_Brightness = 0;
	        }
	        
	        SaveP = (TRUE);
	    }       
	            
	    /*Strobe Pulse Pattern Logic*/
	    if ((StrobePatternPulse == 1) && 
	        (StrobePatternPulseTime < 10)) 
	        {
	            StrobePatternPulseTime ++; 
	        }
	        else
	        {
	            StrobePatternPulse = 0;
	            StrobePatternPulseTime = 0;
	        }
	    
	    /*Reset Fan/AC/Heat MANUAL Signals when in AUTO*/
	    if ((AutoMan == 0) || 
	        (SystemOn == 0))
	        {
	            FanOnMan = 0;
	            AcOnMan = 0;
	            HeatOnMan = 0;
	        }  
	       
	    /*Set Units to F*/
	    p_Units = 0;
	    
	    /*Set Temp Alarms*/
	    if ((kennel1Temp < p_LowerAlarmSetPoint) ||
	        (kennel1Temp > p_UpperAlarmSetPoint))
	        {
	        kennelZone1_bitmap = 2;
	        kennel1Alarm = 1;        
	        }
	    else 
	        {
	        kennelZone1_bitmap = 1; 
	        kennel1Alarm = 0;
	        }
	    
	     if ((kennel2Temp < p_LowerAlarmSetPoint) ||
	        (kennel2Temp > p_UpperAlarmSetPoint))
	        {
	        kennelZone2_bitmap = 2; 
	        kennel2Alarm = 1;
	        }
	        else 
	        {
	        kennelZone2_bitmap = 1; 
	        kennel2Alarm = 0;
	        }
	    
	    if ((kennel3Temp < p_LowerAlarmSetPoint) ||
	        (kennel3Temp > p_UpperAlarmSetPoint))
	        {
	        kennelZone3_bitmap = 2; 
	        kennel3Alarm = 1;
	        }
	    else 
	        {
	        kennelZone3_bitmap = 1; 
	        kennel3Alarm = 0;
	        }
	    
	     if ((kennel4Temp < p_LowerAlarmSetPoint) ||
	        (kennel4Temp > p_UpperAlarmSetPoint))
	        {
	        kennelZone4_bitmap = 2;
	        kennel4Alarm = 1;
	        }
	    else 
	        {
	        kennelZone4_bitmap = 1; 
	        kennel4Alarm = 0;
	        }
	    
	     if ((kennel5Temp < p_LowerAlarmSetPoint) ||
	        (kennel5Temp > p_UpperAlarmSetPoint))
	        {
	        kennelZone5_bitmap = 2;
	        kennel5Alarm = 1;
	        }
	    else 
	        {
	        kennelZone5_bitmap = 1; 
	        kennel5Alarm = 0;
	        }
	    
	     if ((kennel6Temp < p_LowerAlarmSetPoint) ||
	        (kennel6Temp > p_UpperAlarmSetPoint))
	        {
	        kennelZone6_bitmap = 2; 
	        kennel6Alarm = 1;
	        }
	    else 
	        {
	        kennelZone6_bitmap = 1; 
	        kennel6Alarm = 0;
	        }
	        
	    if ((kennel7Temp < p_LowerAlarmSetPoint) ||
	        (kennel7Temp > p_UpperAlarmSetPoint))
	        {
	        kennelZone7_bitmap = 2;
	        kennel7Alarm = 1;        
	        }
	    else 
	        {
	        kennelZone7_bitmap = 1; 
	        kennel7Alarm = 0;
	        }
	        
	    if ((kennel8Temp < p_LowerAlarmSetPoint) ||
	        (kennel8Temp > p_UpperAlarmSetPoint))
	        {
	        kennelZone8_bitmap = 2;
	        kennel8Alarm = 1;        
	        }
	    else 
	        {
	        kennelZone8_bitmap = 1; 
	        kennel8Alarm = 0;
	        }
	    
	
	    /* Save Parameters from Set Up Screen */
	    if (SetupSaveFlag == 1)
	        {
	        SaveP = (TRUE);
	        SetupSaveFlag = 0;
	        }
	    /*Reset Parameter Index Used on Setup Screen */
	    Parameter_Index = 1;
	    
	     /* Go to Set-Up Screen */
	    if (((ind_screen_frame_key_F13).pressedTime > 3000) &&
	        ((ind_screen_frame_key_F15).pressedTime > 3000))
	        {
	          reqScreen = SCREEN_SETUP;            
	        }
	    
	    if (IO_ReverseGear == 1)
	        {
	            reqScreen = SCREEN_CAMERA;
	        
	            if (vt3_screen != reqScreen)
	            {
	                vt3_screen = reqScreen;
	            }
	        
	        }
	        
	    if (vt3_screen != reqScreen)
	        {
	            vt3_screen = reqScreen;
	        }
	        
	        
	     if ((BuzzerTera == 1) &&
	        ((ind_screen_frame_key_F14).eventDown))
	        {
	          SilenceBuzzer = 1;  
	        }
	    else if ((kennel1Alarm == 0) &&
	            (kennel2Alarm == 0) &&
	            (kennel3Alarm == 0) &&
	            (kennel4Alarm == 0) &&
	            (kennel5Alarm == 0) &&
	            (kennel6Alarm == 0) &&
	            (kennel7Alarm == 0) &&
	            (kennel8Alarm == 0) &&
	            (SilenceBuzzer == 1))
	            {
	            SilenceBuzzerReset ++ ;  
	            }
	    if (SilenceBuzzerReset >= 10)
	        {
	            SilenceBuzzer = 0;
	            SilenceBuzzerReset = 0;
	        }
	        
	    if ((kennel1Alarm == 1) &&
	        ((ind_screen_frame_key_F14).eventDown))
	        {
	           kennel1Alarm_Silence = 1; 
	        }
	    else if (kennel1Alarm == 0)
	        {
	            kennel1Alarm_Silence = 0;
	        }
	        
	    if ((kennel2Alarm == 1) &&
	        ((ind_screen_frame_key_F14).eventDown))
	        {
	           kennel2AlarmBuzzer_Silence = 1; 
	        }
	    else if (kennel2Alarm == 0)
	        {
	            kennel2AlarmBuzzer_Silence = 0;
	        }
	        
	    if ((kennel3Alarm == 1) &&
	        ((ind_screen_frame_key_F14).eventDown))
	        {
	           kennel3AlarmBuzzer_Silence = 1; 
	        }
	    else if (kennel3Alarm == 0)
	        {
	            kennel3AlarmBuzzer_Silence = 0;
	        }
	        
	    if ((kennel4Alarm == 1) &&
	        ((ind_screen_frame_key_F14).eventDown))
	        {
	           kennel4AlarmBuzzer_Silence = 1; 
	        }
	    else if (kennel4Alarm == 0)
	        {
	            kennel4AlarmBuzzer_Silence = 0;
	        }
	        
	    if ((kennel5Alarm == 1) &&
	        ((ind_screen_frame_key_F14).eventDown))
	        {
	           kennel5AlarmBuzzer_Silence = 1; 
	        }
	    else if (kennel5Alarm == 0)
	        {
	            kennel5AlarmBuzzer_Silence = 0;
	        }
	        
	    if ((kennel6Alarm == 1) &&
	        ((ind_screen_frame_key_F14).eventDown))
	        {
	           kennel6AlarmBuzzer_Silence = 1; 
	        }
	    else if (kennel6Alarm == 0)
	        {
	            kennel6AlarmBuzzer_Silence = 0;
	        }
	        
	    if ((kennel7Alarm == 1) &&
	        ((ind_screen_frame_key_F14).eventDown))
	        {
	           kennel7AlarmBuzzer_Silence = 1; 
	        }
	    else if (kennel7Alarm == 0)
	        {
	            kennel7AlarmBuzzer_Silence = 0;
	        }
	        
	    if ((kennel8Alarm == 1) &&
	        ((ind_screen_frame_key_F14).eventDown))
	        {
	           kennel8AlarmBuzzer_Silence = 1; 
	        }
	    else if (kennel8Alarm == 0)
	        {
	            kennel8AlarmBuzzer_Silence = 0;
	        }
	        
	}

} /* end of event code for indicator: home */


/* timer event handler for indicator: /project/Tera_7/Screens/home/Logo/multibitmap 
 * runs every 100ms
 */
void vt3_event_ind_home_Logo_multibitmap(
	BYTE event, 
	vt3_indicator_MultiBitmap FARPTR ind)
{
	ind->currentValue = (((SINT)0));

	/* Warning: the code below is generated by vt3.
	 * If you wish to make changes, please use vt3.
	 * 
	 *  node is:    /project/Tera_7/Screens/home/Logo/multibitmap
	 * 
	 * Omitted: the list of replaced identifiers is very long
	 */
	{
	
	}

} /* end of event code for indicator: multibitmap */


/* timer event handler for indicator: /project/Tera_7/Screens/home/F1/Button 
 * runs every 100ms
 */
void vt3_event_ind_home_F1_Button(
	BYTE event, 
	vt3_indicator_MultiBitmap FARPTR ind)
{
	ind->currentValue = ((buttonF1_bitmap));

	/* Warning: the code below is generated by vt3.
	 * If you wish to make changes, please use vt3.
	 * 
	 *  node is:    /project/Tera_7/Screens/home/F1/Button
	 * 
	 * Omitted: the list of replaced identifiers is very long
	 */
	{
	
	}

} /* end of event code for indicator: Button */


/* timer event handler for indicator: /project/Tera_7/Screens/home/F1/Text_1 
 * runs every 100ms
 */
void vt3_event_ind_home_F1_Text_1(
	BYTE event, 
	vt3_indicator_SimpleText FARPTR ind)
{
	static const STRING(6) FAR _str = { 6, 6, "SYSTEM" };
	ind->currentValue = (PSTRING)&_str;

	/* Warning: the code below is generated by vt3.
	 * If you wish to make changes, please use vt3.
	 * 
	 *  node is:    /project/Tera_7/Screens/home/F1/Text_1
	 * 
	 * Omitted: the list of replaced identifiers is very long
	 */
	{
	
	}

} /* end of event code for indicator: Text_1 */


/* timer event handler for indicator: /project/Tera_7/Screens/home/F2/Button 
 * runs every 100ms
 */
void vt3_event_ind_home_F2_Button(
	BYTE event, 
	vt3_indicator_MultiBitmap FARPTR ind)
{
	ind->currentValue = ((buttonF2_bitmap));

	/* Warning: the code below is generated by vt3.
	 * If you wish to make changes, please use vt3.
	 * 
	 *  node is:    /project/Tera_7/Screens/home/F2/Button
	 * 
	 * Omitted: the list of replaced identifiers is very long
	 */
	{
	
	}

} /* end of event code for indicator: Button */


/* timer event handler for indicator: /project/Tera_7/Screens/home/F2/Text_1 
 * runs every 100ms
 */
void vt3_event_ind_home_F2_Text_1(
	BYTE event, 
	vt3_indicator_SimpleText FARPTR ind)
{
	static const STRING(4) FAR _str = { 4, 4, "MODE" };
	ind->currentValue = (PSTRING)&_str;

	/* Warning: the code below is generated by vt3.
	 * If you wish to make changes, please use vt3.
	 * 
	 *  node is:    /project/Tera_7/Screens/home/F2/Text_1
	 * 
	 * Omitted: the list of replaced identifiers is very long
	 */
	{
	
	}

} /* end of event code for indicator: Text_1 */


/* timer event handler for indicator: /project/Tera_7/Screens/home/F2/Auto_Man 
 * runs every 100ms
 */
void vt3_event_ind_home_F2_Auto_Man(
	BYTE event, 
	vt3_indicator_MultiText FARPTR ind)
{
	ind->currentValue = ((buttonF2_text));

	/* Warning: the code below is generated by vt3.
	 * If you wish to make changes, please use vt3.
	 * 
	 *  node is:    /project/Tera_7/Screens/home/F2/Auto_Man
	 * 
	 * Omitted: the list of replaced identifiers is very long
	 */
	{
	
	}

} /* end of event code for indicator: Auto_Man */


/* timer event handler for indicator: /project/Tera_7/Screens/home/F3/Button 
 * runs every 100ms
 */
void vt3_event_ind_home_F3_Button(
	BYTE event, 
	vt3_indicator_MultiBitmap FARPTR ind)
{
	ind->currentValue = ((buttonF3_bitmap));

	/* Warning: the code below is generated by vt3.
	 * If you wish to make changes, please use vt3.
	 * 
	 *  node is:    /project/Tera_7/Screens/home/F3/Button
	 * 
	 * Omitted: the list of replaced identifiers is very long
	 */
	{
	
	}

} /* end of event code for indicator: Button */


/* timer event handler for indicator: /project/Tera_7/Screens/home/F3/Text_1 
 * runs every 100ms
 */
void vt3_event_ind_home_F3_Text_1(
	BYTE event, 
	vt3_indicator_SimpleText FARPTR ind)
{
	static const STRING(3) FAR _str = { 3, 3, "FAN" };
	ind->currentValue = (PSTRING)&_str;

	/* Warning: the code below is generated by vt3.
	 * If you wish to make changes, please use vt3.
	 * 
	 *  node is:    /project/Tera_7/Screens/home/F3/Text_1
	 * 
	 * Omitted: the list of replaced identifiers is very long
	 */
	{
	
	}

} /* end of event code for indicator: Text_1 */


/* timer event handler for indicator: /project/Tera_7/Screens/home/F4/Button 
 * runs every 100ms
 */
void vt3_event_ind_home_F4_Button(
	BYTE event, 
	vt3_indicator_MultiBitmap FARPTR ind)
{
	ind->currentValue = ((buttonF4_bitmap));

	/* Warning: the code below is generated by vt3.
	 * If you wish to make changes, please use vt3.
	 * 
	 *  node is:    /project/Tera_7/Screens/home/F4/Button
	 * 
	 * Omitted: the list of replaced identifiers is very long
	 */
	{
	
	}

} /* end of event code for indicator: Button */


/* timer event handler for indicator: /project/Tera_7/Screens/home/F4/Text_1 
 * runs every 100ms
 */
void vt3_event_ind_home_F4_Text_1(
	BYTE event, 
	vt3_indicator_SimpleText FARPTR ind)
{
	static const STRING(2) FAR _str = { 2, 2, "AC" };
	ind->currentValue = (PSTRING)&_str;

	/* Warning: the code below is generated by vt3.
	 * If you wish to make changes, please use vt3.
	 * 
	 *  node is:    /project/Tera_7/Screens/home/F4/Text_1
	 * 
	 * Omitted: the list of replaced identifiers is very long
	 */
	{
	
	}

} /* end of event code for indicator: Text_1 */


/* timer event handler for indicator: /project/Tera_7/Screens/home/F5/Button 
 * runs every 100ms
 */
void vt3_event_ind_home_F5_Button(
	BYTE event, 
	vt3_indicator_MultiBitmap FARPTR ind)
{
	ind->currentValue = ((buttonF5_bitmap));

	/* Warning: the code below is generated by vt3.
	 * If you wish to make changes, please use vt3.
	 * 
	 *  node is:    /project/Tera_7/Screens/home/F5/Button
	 * 
	 * Omitted: the list of replaced identifiers is very long
	 */
	{
	
	}

} /* end of event code for indicator: Button */


/* timer event handler for indicator: /project/Tera_7/Screens/home/F5/Text_1 
 * runs every 100ms
 */
void vt3_event_ind_home_F5_Text_1(
	BYTE event, 
	vt3_indicator_SimpleText FARPTR ind)
{
	static const STRING(4) FAR _str = { 4, 4, "HEAT" };
	ind->currentValue = (PSTRING)&_str;

	/* Warning: the code below is generated by vt3.
	 * If you wish to make changes, please use vt3.
	 * 
	 *  node is:    /project/Tera_7/Screens/home/F5/Text_1
	 * 
	 * Omitted: the list of replaced identifiers is very long
	 */
	{
	
	}

} /* end of event code for indicator: Text_1 */


/* timer event handler for indicator: /project/Tera_7/Screens/home/F6/Button 
 * runs every 100ms
 */
void vt3_event_ind_home_F6_Button(
	BYTE event, 
	vt3_indicator_MultiBitmap FARPTR ind)
{
	ind->currentValue = ((buttonF6_bitmap));

	/* Warning: the code below is generated by vt3.
	 * If you wish to make changes, please use vt3.
	 * 
	 *  node is:    /project/Tera_7/Screens/home/F6/Button
	 * 
	 * Omitted: the list of replaced identifiers is very long
	 */
	{
	
	}

} /* end of event code for indicator: Button */


/* timer event handler for indicator: /project/Tera_7/Screens/home/F6/Text_1 
 * runs every 100ms
 */
void vt3_event_ind_home_F6_Text_1(
	BYTE event, 
	vt3_indicator_SimpleText FARPTR ind)
{
	static const STRING(16) FAR _str = { 16, 16, "INTERIOR\n LIGHTS" };
	ind->currentValue = (PSTRING)&_str;

	/* Warning: the code below is generated by vt3.
	 * If you wish to make changes, please use vt3.
	 * 
	 *  node is:    /project/Tera_7/Screens/home/F6/Text_1
	 * 
	 * Omitted: the list of replaced identifiers is very long
	 */
	{
	
	}

} /* end of event code for indicator: Text_1 */


/* timer event handler for indicator: /project/Tera_7/Screens/home/F9/Button 
 * runs every 100ms
 */
void vt3_event_ind_home_F9_Button(
	BYTE event, 
	vt3_indicator_MultiBitmap FARPTR ind)
{
	ind->currentValue = ((buttonF9_bitmap));

	/* Warning: the code below is generated by vt3.
	 * If you wish to make changes, please use vt3.
	 * 
	 *  node is:    /project/Tera_7/Screens/home/F9/Button
	 * 
	 * Omitted: the list of replaced identifiers is very long
	 */
	{
	
	}

} /* end of event code for indicator: Button */


/* timer event handler for indicator: /project/Tera_7/Screens/home/F9/Text_1 
 * runs every 100ms
 */
void vt3_event_ind_home_F9_Text_1(
	BYTE event, 
	vt3_indicator_SimpleText FARPTR ind)
{
	static const STRING(14) FAR _str = { 14, 14, "STROBE\n LIGHTS" };
	ind->currentValue = (PSTRING)&_str;

	/* Warning: the code below is generated by vt3.
	 * If you wish to make changes, please use vt3.
	 * 
	 *  node is:    /project/Tera_7/Screens/home/F9/Text_1
	 * 
	 * Omitted: the list of replaced identifiers is very long
	 */
	{
	
	}

} /* end of event code for indicator: Text_1 */


/* timer event handler for indicator: /project/Tera_7/Screens/home/F10/Button 
 * runs every 100ms
 */
void vt3_event_ind_home_F10_Button(
	BYTE event, 
	vt3_indicator_MultiBitmap FARPTR ind)
{
	ind->currentValue = ((buttonF10_bitmap));

	/* Warning: the code below is generated by vt3.
	 * If you wish to make changes, please use vt3.
	 * 
	 *  node is:    /project/Tera_7/Screens/home/F10/Button
	 * 
	 * Omitted: the list of replaced identifiers is very long
	 */
	{
	
	}

} /* end of event code for indicator: Button */


/* timer event handler for indicator: /project/Tera_7/Screens/home/F10/Text_1 
 * runs every 100ms
 */
void vt3_event_ind_home_F10_Text_1(
	BYTE event, 
	vt3_indicator_SimpleText FARPTR ind)
{
	static const STRING(15) FAR _str = { 15, 15, "STROBE\n PATTERN" };
	ind->currentValue = (PSTRING)&_str;

	/* Warning: the code below is generated by vt3.
	 * If you wish to make changes, please use vt3.
	 * 
	 *  node is:    /project/Tera_7/Screens/home/F10/Text_1
	 * 
	 * Omitted: the list of replaced identifiers is very long
	 */
	{
	
	}

} /* end of event code for indicator: Text_1 */


/* timer event handler for indicator: /project/Tera_7/Screens/home/Temp_1/multibitmap 
 * runs every 100ms
 */
void vt3_event_ind_home_Temp_1_multibitmap(
	BYTE event, 
	vt3_indicator_MultiBitmap FARPTR ind)
{
	ind->currentValue = ((kennelZone1_bitmap));

	/* Warning: the code below is generated by vt3.
	 * If you wish to make changes, please use vt3.
	 * 
	 *  node is:    /project/Tera_7/Screens/home/Temp_1/multibitmap
	 * 
	 * Omitted: the list of replaced identifiers is very long
	 */
	{
	
	}

} /* end of event code for indicator: multibitmap */


/* timer event handler for indicator: /project/Tera_7/Screens/home/Temp_1/Temp 
 * runs every 100ms
 */
void vt3_event_ind_home_Temp_1_Temp(
	BYTE event, 
	vt3_indicator_Number FARPTR ind)
{
	ind->currentValue = ((kennel1Temp));

	/* Warning: the code below is generated by vt3.
	 * If you wish to make changes, please use vt3.
	 * 
	 *  node is:    /project/Tera_7/Screens/home/Temp_1/Temp
	 * 
	 * Omitted: the list of replaced identifiers is very long
	 */
	{
	
	}

} /* end of event code for indicator: Temp */


/* timer event handler for indicator: /project/Tera_7/Screens/home/Temp_1/multitext 
 * runs every 100ms
 */
void vt3_event_ind_home_Temp_1_multitext(
	BYTE event, 
	vt3_indicator_MultiText FARPTR ind)
{
	ind->currentValue = ((p_Units));

	/* Warning: the code below is generated by vt3.
	 * If you wish to make changes, please use vt3.
	 * 
	 *  node is:    /project/Tera_7/Screens/home/Temp_1/multitext
	 * 
	 * Omitted: the list of replaced identifiers is very long
	 */
	{
	
	}

} /* end of event code for indicator: multitext */


/* timer event handler for indicator: /project/Tera_7/Screens/home/Temp_1/simple_text 
 * runs every 100ms
 */
void vt3_event_ind_home_Temp_1_simple_text(
	BYTE event, 
	vt3_indicator_SimpleText FARPTR ind)
{
	static const STRING(1) FAR _str = { 1, 1, "o" };
	ind->currentValue = (PSTRING)&_str;

	/* Warning: the code below is generated by vt3.
	 * If you wish to make changes, please use vt3.
	 * 
	 *  node is:    /project/Tera_7/Screens/home/Temp_1/simple_text
	 * 
	 * Omitted: the list of replaced identifiers is very long
	 */
	{
	
	}

} /* end of event code for indicator: simple_text */


/* timer event handler for indicator: /project/Tera_7/Screens/home/Temp_2/multibitmap 
 * runs every 100ms
 */
void vt3_event_ind_home_Temp_2_multibitmap(
	BYTE event, 
	vt3_indicator_MultiBitmap FARPTR ind)
{
	ind->currentValue = ((kennelZone2_bitmap));

	/* Warning: the code below is generated by vt3.
	 * If you wish to make changes, please use vt3.
	 * 
	 *  node is:    /project/Tera_7/Screens/home/Temp_2/multibitmap
	 * 
	 * Omitted: the list of replaced identifiers is very long
	 */
	{
	
	}

} /* end of event code for indicator: multibitmap */


/* timer event handler for indicator: /project/Tera_7/Screens/home/Temp_2/Temp 
 * runs every 100ms
 */
void vt3_event_ind_home_Temp_2_Temp(
	BYTE event, 
	vt3_indicator_Number FARPTR ind)
{
	ind->currentValue = ((kennel2Temp));

	/* Warning: the code below is generated by vt3.
	 * If you wish to make changes, please use vt3.
	 * 
	 *  node is:    /project/Tera_7/Screens/home/Temp_2/Temp
	 * 
	 * Omitted: the list of replaced identifiers is very long
	 */
	{
	
	}

} /* end of event code for indicator: Temp */


/* timer event handler for indicator: /project/Tera_7/Screens/home/Temp_2/multitext 
 * runs every 100ms
 */
void vt3_event_ind_home_Temp_2_multitext(
	BYTE event, 
	vt3_indicator_MultiText FARPTR ind)
{
	ind->currentValue = ((p_Units));

	/* Warning: the code below is generated by vt3.
	 * If you wish to make changes, please use vt3.
	 * 
	 *  node is:    /project/Tera_7/Screens/home/Temp_2/multitext
	 * 
	 * Omitted: the list of replaced identifiers is very long
	 */
	{
	
	}

} /* end of event code for indicator: multitext */


/* timer event handler for indicator: /project/Tera_7/Screens/home/Temp_2/simple_text 
 * runs every 100ms
 */
void vt3_event_ind_home_Temp_2_simple_text(
	BYTE event, 
	vt3_indicator_SimpleText FARPTR ind)
{
	static const STRING(1) FAR _str = { 1, 1, "o" };
	ind->currentValue = (PSTRING)&_str;

	/* Warning: the code below is generated by vt3.
	 * If you wish to make changes, please use vt3.
	 * 
	 *  node is:    /project/Tera_7/Screens/home/Temp_2/simple_text
	 * 
	 * Omitted: the list of replaced identifiers is very long
	 */
	{
	
	}

} /* end of event code for indicator: simple_text */


/* timer event handler for indicator: /project/Tera_7/Screens/home/Temp_5/multibitmap 
 * runs every 100ms
 */
void vt3_event_ind_home_Temp_5_multibitmap(
	BYTE event, 
	vt3_indicator_MultiBitmap FARPTR ind)
{
	ind->currentValue = ((kennelZone5_bitmap));

	/* Warning: the code below is generated by vt3.
	 * If you wish to make changes, please use vt3.
	 * 
	 *  node is:    /project/Tera_7/Screens/home/Temp_5/multibitmap
	 * 
	 * Omitted: the list of replaced identifiers is very long
	 */
	{
	
	}

} /* end of event code for indicator: multibitmap */


/* timer event handler for indicator: /project/Tera_7/Screens/home/Temp_5/Temp 
 * runs every 100ms
 */
void vt3_event_ind_home_Temp_5_Temp(
	BYTE event, 
	vt3_indicator_Number FARPTR ind)
{
	ind->currentValue = ((kennel5Temp));

	/* Warning: the code below is generated by vt3.
	 * If you wish to make changes, please use vt3.
	 * 
	 *  node is:    /project/Tera_7/Screens/home/Temp_5/Temp
	 * 
	 * Omitted: the list of replaced identifiers is very long
	 */
	{
	
	}

} /* end of event code for indicator: Temp */


/* timer event handler for indicator: /project/Tera_7/Screens/home/Temp_5/multitext 
 * runs every 100ms
 */
void vt3_event_ind_home_Temp_5_multitext(
	BYTE event, 
	vt3_indicator_MultiText FARPTR ind)
{
	ind->currentValue = ((p_Units));

	/* Warning: the code below is generated by vt3.
	 * If you wish to make changes, please use vt3.
	 * 
	 *  node is:    /project/Tera_7/Screens/home/Temp_5/multitext
	 * 
	 * Omitted: the list of replaced identifiers is very long
	 */
	{
	
	}

} /* end of event code for indicator: multitext */


/* timer event handler for indicator: /project/Tera_7/Screens/home/Temp_5/simple_text 
 * runs every 100ms
 */
void vt3_event_ind_home_Temp_5_simple_text(
	BYTE event, 
	vt3_indicator_SimpleText FARPTR ind)
{
	static const STRING(1) FAR _str = { 1, 1, "o" };
	ind->currentValue = (PSTRING)&_str;

	/* Warning: the code below is generated by vt3.
	 * If you wish to make changes, please use vt3.
	 * 
	 *  node is:    /project/Tera_7/Screens/home/Temp_5/simple_text
	 * 
	 * Omitted: the list of replaced identifiers is very long
	 */
	{
	
	}

} /* end of event code for indicator: simple_text */


/* timer event handler for indicator: /project/Tera_7/Screens/home/multitext 
 * runs every 100ms
 */
void vt3_event_ind_home_multitext(
	BYTE event, 
	vt3_indicator_MultiText FARPTR ind)
{
	ind->currentValue = ((AlarmMessage));

	/* Warning: the code below is generated by vt3.
	 * If you wish to make changes, please use vt3.
	 * 
	 *  node is:    /project/Tera_7/Screens/home/multitext
	 * 
	 * Omitted: the list of replaced identifiers is very long
	 */
	{
	
	}

} /* end of event code for indicator: multitext */


/* timer event handler for indicator: /project/Tera_7/Screens/home/simple_text 
 * runs every 100ms
 */
void vt3_event_ind_home_simple_text(
	BYTE event, 
	vt3_indicator_SimpleText FARPTR ind)
{
	static const STRING(7) FAR _str = { 7, 7, "STORAGE" };
	ind->currentValue = (PSTRING)&_str;

	/* Warning: the code below is generated by vt3.
	 * If you wish to make changes, please use vt3.
	 * 
	 *  node is:    /project/Tera_7/Screens/home/simple_text
	 * 
	 * Omitted: the list of replaced identifiers is very long
	 */
	{
	
	}

} /* end of event code for indicator: simple_text */


/* timer event handler for indicator: /project/Tera_7/Screens/home/F7/Button 
 * runs every 100ms
 */
void vt3_event_ind_home_F7_Button(
	BYTE event, 
	vt3_indicator_MultiBitmap FARPTR ind)
{
	ind->currentValue = ((buttonF7_bitmap));


} /* end of event code for indicator: Button */


/* timer event handler for indicator: /project/Tera_7/Screens/home/F7/Text_1 
 * runs every 100ms
 */
void vt3_event_ind_home_F7_Text_1(
	BYTE event, 
	vt3_indicator_SimpleText FARPTR ind)
{
	static const STRING(6) FAR _str = { 6, 6, "CAMERA" };
	ind->currentValue = (PSTRING)&_str;

	/* Warning: the code below is generated by vt3.
	 * If you wish to make changes, please use vt3.
	 * 
	 *  node is:    /project/Tera_7/Screens/home/F7/Text_1
	 * 
	 * Omitted: the list of replaced identifiers is very long
	 */
	{
	
	}

} /* end of event code for indicator: Text_1 */


/* timer event handler for indicator: /project/Tera_7/Screens/home/group/multibitmap 
 * runs every 100ms
 */
void vt3_event_ind_home_group_multibitmap(
	BYTE event, 
	vt3_indicator_MultiBitmap FARPTR ind)
{
	ind->currentValue = ((kennelZone3_bitmap));

	/* Warning: the code below is generated by vt3.
	 * If you wish to make changes, please use vt3.
	 * 
	 *  node is:    /project/Tera_7/Screens/home/group/multibitmap
	 * 
	 * Omitted: the list of replaced identifiers is very long
	 */
	{
	
	}

} /* end of event code for indicator: multibitmap */


/* timer event handler for indicator: /project/Tera_7/Screens/home/group/multitext 
 * runs every 100ms
 */
void vt3_event_ind_home_group_multitext(
	BYTE event, 
	vt3_indicator_MultiText FARPTR ind)
{
	ind->currentValue = ((p_Units));

	/* Warning: the code below is generated by vt3.
	 * If you wish to make changes, please use vt3.
	 * 
	 *  node is:    /project/Tera_7/Screens/home/group/multitext
	 * 
	 * Omitted: the list of replaced identifiers is very long
	 */
	{
	
	}

} /* end of event code for indicator: multitext */


/* timer event handler for indicator: /project/Tera_7/Screens/home/group/Temp 
 * runs every 100ms
 */
void vt3_event_ind_home_group_Temp(
	BYTE event, 
	vt3_indicator_Number FARPTR ind)
{
	ind->currentValue = ((kennel3Temp));

	/* Warning: the code below is generated by vt3.
	 * If you wish to make changes, please use vt3.
	 * 
	 *  node is:    /project/Tera_7/Screens/home/group/Temp
	 * 
	 * Omitted: the list of replaced identifiers is very long
	 */
	{
	
	}

} /* end of event code for indicator: Temp */


/* timer event handler for indicator: /project/Tera_7/Screens/home/group/simple_text 
 * runs every 100ms
 */
void vt3_event_ind_home_group_simple_text(
	BYTE event, 
	vt3_indicator_SimpleText FARPTR ind)
{
	static const STRING(1) FAR _str = { 1, 1, "o" };
	ind->currentValue = (PSTRING)&_str;

	/* Warning: the code below is generated by vt3.
	 * If you wish to make changes, please use vt3.
	 * 
	 *  node is:    /project/Tera_7/Screens/home/group/simple_text
	 * 
	 * Omitted: the list of replaced identifiers is very long
	 */
	{
	
	}

} /* end of event code for indicator: simple_text */


/* timer event handler for indicator: /project/Tera_7/Screens/home/group_2/multibitmap 
 * runs every 100ms
 */
void vt3_event_ind_home_group_2_multibitmap(
	BYTE event, 
	vt3_indicator_MultiBitmap FARPTR ind)
{
	ind->currentValue = ((kennelZone4_bitmap));

	/* Warning: the code below is generated by vt3.
	 * If you wish to make changes, please use vt3.
	 * 
	 *  node is:    /project/Tera_7/Screens/home/group_2/multibitmap
	 * 
	 * Omitted: the list of replaced identifiers is very long
	 */
	{
	
	}

} /* end of event code for indicator: multibitmap */


/* timer event handler for indicator: /project/Tera_7/Screens/home/group_2/multitext 
 * runs every 100ms
 */
void vt3_event_ind_home_group_2_multitext(
	BYTE event, 
	vt3_indicator_MultiText FARPTR ind)
{
	ind->currentValue = ((p_Units));

	/* Warning: the code below is generated by vt3.
	 * If you wish to make changes, please use vt3.
	 * 
	 *  node is:    /project/Tera_7/Screens/home/group_2/multitext
	 * 
	 * Omitted: the list of replaced identifiers is very long
	 */
	{
	
	}

} /* end of event code for indicator: multitext */


/* timer event handler for indicator: /project/Tera_7/Screens/home/group_2/Temp 
 * runs every 100ms
 */
void vt3_event_ind_home_group_2_Temp(
	BYTE event, 
	vt3_indicator_Number FARPTR ind)
{
	ind->currentValue = ((kennel4Temp));

	/* Warning: the code below is generated by vt3.
	 * If you wish to make changes, please use vt3.
	 * 
	 *  node is:    /project/Tera_7/Screens/home/group_2/Temp
	 * 
	 * Omitted: the list of replaced identifiers is very long
	 */
	{
	
	}

} /* end of event code for indicator: Temp */


/* timer event handler for indicator: /project/Tera_7/Screens/home/group_2/simple_text 
 * runs every 100ms
 */
void vt3_event_ind_home_group_2_simple_text(
	BYTE event, 
	vt3_indicator_SimpleText FARPTR ind)
{
	static const STRING(1) FAR _str = { 1, 1, "o" };
	ind->currentValue = (PSTRING)&_str;

	/* Warning: the code below is generated by vt3.
	 * If you wish to make changes, please use vt3.
	 * 
	 *  node is:    /project/Tera_7/Screens/home/group_2/simple_text
	 * 
	 * Omitted: the list of replaced identifiers is very long
	 */
	{
	
	}

} /* end of event code for indicator: simple_text */


/* timer event handler for indicator: /project/Tera_7/Screens/home/group_4/multibitmap 
 * runs every 100ms
 */
void vt3_event_ind_home_group_4_multibitmap(
	BYTE event, 
	vt3_indicator_MultiBitmap FARPTR ind)
{
	ind->currentValue = ((kennelZone7_bitmap));

	/* Warning: the code below is generated by vt3.
	 * If you wish to make changes, please use vt3.
	 * 
	 *  node is:    /project/Tera_7/Screens/home/group_4/multibitmap
	 * 
	 * Omitted: the list of replaced identifiers is very long
	 */
	{
	
	}

} /* end of event code for indicator: multibitmap */


/* timer event handler for indicator: /project/Tera_7/Screens/home/group_4/multitext 
 * runs every 100ms
 */
void vt3_event_ind_home_group_4_multitext(
	BYTE event, 
	vt3_indicator_MultiText FARPTR ind)
{
	ind->currentValue = ((p_Units));

	/* Warning: the code below is generated by vt3.
	 * If you wish to make changes, please use vt3.
	 * 
	 *  node is:    /project/Tera_7/Screens/home/group_4/multitext
	 * 
	 * Omitted: the list of replaced identifiers is very long
	 */
	{
	
	}

} /* end of event code for indicator: multitext */


/* timer event handler for indicator: /project/Tera_7/Screens/home/group_4/Temp 
 * runs every 100ms
 */
void vt3_event_ind_home_group_4_Temp(
	BYTE event, 
	vt3_indicator_Number FARPTR ind)
{
	ind->currentValue = ((kennel7Temp));

	/* Warning: the code below is generated by vt3.
	 * If you wish to make changes, please use vt3.
	 * 
	 *  node is:    /project/Tera_7/Screens/home/group_4/Temp
	 * 
	 * Omitted: the list of replaced identifiers is very long
	 */
	{
	
	}

} /* end of event code for indicator: Temp */


/* timer event handler for indicator: /project/Tera_7/Screens/home/group_4/simple_text 
 * runs every 100ms
 */
void vt3_event_ind_home_group_4_simple_text(
	BYTE event, 
	vt3_indicator_SimpleText FARPTR ind)
{
	static const STRING(1) FAR _str = { 1, 1, "o" };
	ind->currentValue = (PSTRING)&_str;

	/* Warning: the code below is generated by vt3.
	 * If you wish to make changes, please use vt3.
	 * 
	 *  node is:    /project/Tera_7/Screens/home/group_4/simple_text
	 * 
	 * Omitted: the list of replaced identifiers is very long
	 */
	{
	
	}

} /* end of event code for indicator: simple_text */


/* timer event handler for indicator: /project/Tera_7/Screens/home/group_5/multibitmap 
 * runs every 100ms
 */
void vt3_event_ind_home_group_5_multibitmap(
	BYTE event, 
	vt3_indicator_MultiBitmap FARPTR ind)
{
	ind->currentValue = ((kennelZone8_bitmap));

	/* Warning: the code below is generated by vt3.
	 * If you wish to make changes, please use vt3.
	 * 
	 *  node is:    /project/Tera_7/Screens/home/group_5/multibitmap
	 * 
	 * Omitted: the list of replaced identifiers is very long
	 */
	{
	
	}

} /* end of event code for indicator: multibitmap */


/* timer event handler for indicator: /project/Tera_7/Screens/home/group_5/multitext 
 * runs every 100ms
 */
void vt3_event_ind_home_group_5_multitext(
	BYTE event, 
	vt3_indicator_MultiText FARPTR ind)
{
	ind->currentValue = ((p_Units));

	/* Warning: the code below is generated by vt3.
	 * If you wish to make changes, please use vt3.
	 * 
	 *  node is:    /project/Tera_7/Screens/home/group_5/multitext
	 * 
	 * Omitted: the list of replaced identifiers is very long
	 */
	{
	
	}

} /* end of event code for indicator: multitext */


/* timer event handler for indicator: /project/Tera_7/Screens/home/group_5/Temp 
 * runs every 100ms
 */
void vt3_event_ind_home_group_5_Temp(
	BYTE event, 
	vt3_indicator_Number FARPTR ind)
{
	ind->currentValue = ((kennel8Temp));

	/* Warning: the code below is generated by vt3.
	 * If you wish to make changes, please use vt3.
	 * 
	 *  node is:    /project/Tera_7/Screens/home/group_5/Temp
	 * 
	 * Omitted: the list of replaced identifiers is very long
	 */
	{
	
	}

} /* end of event code for indicator: Temp */


/* timer event handler for indicator: /project/Tera_7/Screens/home/group_5/simple_text 
 * runs every 100ms
 */
void vt3_event_ind_home_group_5_simple_text(
	BYTE event, 
	vt3_indicator_SimpleText FARPTR ind)
{
	static const STRING(1) FAR _str = { 1, 1, "o" };
	ind->currentValue = (PSTRING)&_str;

	/* Warning: the code below is generated by vt3.
	 * If you wish to make changes, please use vt3.
	 * 
	 *  node is:    /project/Tera_7/Screens/home/group_5/simple_text
	 * 
	 * Omitted: the list of replaced identifiers is very long
	 */
	{
	
	}

} /* end of event code for indicator: simple_text */


/* timer event handler for indicator: /project/Tera_7/Screens/home/group_3/multibitmap 
 * runs every 100ms
 */
void vt3_event_ind_home_group_3_multibitmap(
	BYTE event, 
	vt3_indicator_MultiBitmap FARPTR ind)
{
	ind->currentValue = ((kennelZone6_bitmap));

	/* Warning: the code below is generated by vt3.
	 * If you wish to make changes, please use vt3.
	 * 
	 *  node is:    /project/Tera_7/Screens/home/group_3/multibitmap
	 * 
	 * Omitted: the list of replaced identifiers is very long
	 */
	{
	
	}

} /* end of event code for indicator: multibitmap */


/* timer event handler for indicator: /project/Tera_7/Screens/home/group_3/multitext 
 * runs every 100ms
 */
void vt3_event_ind_home_group_3_multitext(
	BYTE event, 
	vt3_indicator_MultiText FARPTR ind)
{
	ind->currentValue = ((p_Units));

	/* Warning: the code below is generated by vt3.
	 * If you wish to make changes, please use vt3.
	 * 
	 *  node is:    /project/Tera_7/Screens/home/group_3/multitext
	 * 
	 * Omitted: the list of replaced identifiers is very long
	 */
	{
	
	}

} /* end of event code for indicator: multitext */


/* timer event handler for indicator: /project/Tera_7/Screens/home/group_3/Temp 
 * runs every 100ms
 */
void vt3_event_ind_home_group_3_Temp(
	BYTE event, 
	vt3_indicator_Number FARPTR ind)
{
	ind->currentValue = ((kennel6Temp));

	/* Warning: the code below is generated by vt3.
	 * If you wish to make changes, please use vt3.
	 * 
	 *  node is:    /project/Tera_7/Screens/home/group_3/Temp
	 * 
	 * Omitted: the list of replaced identifiers is very long
	 */
	{
	
	}

} /* end of event code for indicator: Temp */


/* timer event handler for indicator: /project/Tera_7/Screens/home/group_3/simple_text 
 * runs every 100ms
 */
void vt3_event_ind_home_group_3_simple_text(
	BYTE event, 
	vt3_indicator_SimpleText FARPTR ind)
{
	static const STRING(1) FAR _str = { 1, 1, "o" };
	ind->currentValue = (PSTRING)&_str;

	/* Warning: the code below is generated by vt3.
	 * If you wish to make changes, please use vt3.
	 * 
	 *  node is:    /project/Tera_7/Screens/home/group_3/simple_text
	 * 
	 * Omitted: the list of replaced identifiers is very long
	 */
	{
	
	}

} /* end of event code for indicator: simple_text */


#endif /* INCLUDE__VT3_EVENT__HOME_C */

/* end of file */