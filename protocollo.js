// var ritorno =  $prop('ThrustmastersPlugin.OverallGain').toString() +';';
ritorno = ritorno + isnull($prop('DataCorePlugin.GameData.NewData.Gear'),   'N').toString()             + ';' ;
ritorno = ritorno + format($prop('DataCorePlugin.GameData.NewData.SpeedKmh'),'0' ).toString()      + ';' ;
ritorno = ritorno + format($prop('DataCorePlugin.GameData.NewData.Rpms' )  ,'0' ).toString()          + ';' ;
// if(ritorno.substring(0,1)==0)
// {
	
	ritorno = ritorno + format($prop('DataCorePlugin.GameData.NewData.MaxRpm')   ,'0' ).toString()       + ';' ;
	ritorno = ritorno + $prop('DataCorePlugin.GameData.NewData.CurrentLapTime').toString().substring(3,10)           + ';' ;
	ritorno = ritorno + $prop('DataCorePlugin.GameData.NewData.BestLapTime').toString().substring(3,12)      + ';' ;
	ritorno = ritorno + $prop('DataCorePlugin.GameData.NewData.DRSAvailable').toString()                   + ';' ;
	ritorno = ritorno + $prop('DataCorePlugin.GameData.NewData.DRSEnabled').toString()                    +';';
	ritorno = ritorno + $prop('DataCorePlugin.GameData.NewData.LastLapTime').toString().substring(3,12)       +';';
	ritorno = ritorno + $prop('PersistantTrackerPlugin.SessionBestLastSectorDeltaSeconds').toString()  +';';
	ritorno = ritorno + $prop('DataCorePlugin.CustomExpression.CurrentDateTime').toString().substring(22,24) + ';';
	
	if($prop('DataCorePlugin.CurrentGame')==("F12017") || $prop('DataCorePlugin.CurrentGame')==("F12018"))
	{
	    	ritorno += "0";
	}
	else
	{   
		var ers=($prop('DataCorePlugin.GameRawData.Physics.KersCharge')*100).toString();
		ers=ers.substring(0,ers.indexOf("."));
		if(ers=="")
		{
			ers=0;
		}
	    	ritorno += ers; 
	}
// }
// else if (ritorno.substring(0,1)==1)
// {
// 	ritorno = ritorno + $prop('DataCorePlugin.GameRawData.Physics.ErsPowerLevel')+';';
// 	ritorno = ritorno + $prop('DataCorePlugin.GameRawData.Physics.ErsRecoveryLevel')+';';	
// 	ritorno = ritorno + $prop('DataCorePlugin.GameRawData.Physics.ErsHeatCharging');
// }
// else if (ritorno.substring(0,1)==2)
// {
// }
return ritorno;