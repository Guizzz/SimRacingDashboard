// var ret =  $prop('ThrustmastersPlugin.OverallGain').toString() +';';
ret = ret + isnull($prop('DataCorePlugin.GameData.NewData.Gear'),   'N').toString()             + ';' ;
ret = ret + format($prop('DataCorePlugin.GameData.NewData.SpeedKmh'),'0' ).toString()      + ';' ;
ret = ret + format($prop('DataCorePlugin.GameData.NewData.Rpms' )  ,'0' ).toString()          + ';' ;
// if(ret.substring(0,1)==0)
// {
	
	ret = ret + format($prop('DataCorePlugin.GameData.NewData.MaxRpm')   ,'0' ).toString()       + ';' ;
	ret = ret + $prop('DataCorePlugin.GameData.NewData.CurrentLapTime').toString().substring(3,10)           + ';' ;
	ret = ret + $prop('DataCorePlugin.GameData.NewData.BestLapTime').toString().substring(3,12)      + ';' ;
	ret = ret + $prop('DataCorePlugin.GameData.NewData.DRSAvailable').toString()                   + ';' ;
	ret = ret + $prop('DataCorePlugin.GameData.NewData.DRSEnabled').toString()                    +';';
	ret = ret + $prop('DataCorePlugin.GameData.NewData.LastLapTime').toString().substring(3,12)       +';';
	ret = ret + $prop('PersistantTrackerPlugin.SessionBestLastSectorDeltaSeconds').toString()  +';';
	ret = ret + $prop('DataCorePlugin.CustomExpression.CurrentDateTime').toString().substring(22,24) + ';';
	
	if($prop('DataCorePlugin.CurrentGame')==("F12017") || $prop('DataCorePlugin.CurrentGame')==("F12018"))
	{
	    	ret += "0";
	}
	else
	{   
		var ers=($prop('DataCorePlugin.GameRawData.Physics.KersCharge')*100).toString();
		ers=ers.substring(0,ers.indexOf("."));
		if(ers=="")
		{
			ers=0;
		}
	    	ret += ers; 
	}
// }
// else if (ret.substring(0,1)==1)
// {
// 	ret = ret + $prop('DataCorePlugin.GameRawData.Physics.ErsPowerLevel')+';';
// 	ret = ret + $prop('DataCorePlugin.GameRawData.Physics.ErsRecoveryLevel')+';';	
// 	ret = ret + $prop('DataCorePlugin.GameRawData.Physics.ErsHeatCharging');
// }
// else if (ret.substring(0,1)==2)
// {
// }
return ret;
