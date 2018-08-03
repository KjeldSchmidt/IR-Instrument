using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class VolumeController : MonoBehaviour {

	AudioSource[] sources;

	// Use this for initialization
	void Start () {
		 sources = GetComponents<AudioSource>();
	}

	 // Invoked when a line of data is received from the serial device.
	void OnMessageArrived(string msg)
	{
		float[] volumes = splitMessage( msg );
		for ( int i = 0; i < sources.Length && i < volumes.Length; i++ ) {
			sources[i].volume = volumes[i];	
		}
	}

	// Invoked when a connect/disconnect event occurs. The parameter 'success'
	// will be 'true' upon connection, and 'false' upon disconnection or
	// failure to connect.
	void OnConnectionEvent(bool success)
	{
		silenceAll();
	}

	void silenceAll() {
		for ( int i = 0; i < sources.Length; i++ ) {
			sources[i].volume = 0;
		}
	}

	float[] splitMessage( string message ) {
		string[] volume_abs_strings = message.Split(' ');
		float[] volumes = Array.ConvertAll( volume_abs_strings, float.Parse );
		for ( int i = 0; i < volumes.Length; i++ ) {
			volumes[i] = Math.Min( volumes[i]/500, 1.0f );
		}

		return volumes;
	}


}
