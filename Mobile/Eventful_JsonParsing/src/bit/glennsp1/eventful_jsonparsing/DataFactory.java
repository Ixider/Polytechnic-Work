package bit.glennsp1.eventful_jsonparsing;


import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;

import org.apache.http.HttpEntity;
import org.apache.http.HttpResponse;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.impl.client.DefaultHttpClient;

import android.content.Context;
import android.os.AsyncTask;

public class DataFactory {
	//These should probably be in res/string
	private static final String API_KEY = "X7dwZ7srgVXWD7DB";
	private static final String API_END_POINT = "http://api.eventful.com/json/events/search?app_key=";
	private static final String QUERY_URL = "&q=";
	private static final String LOCATION_URL = "&l=New+Zealand+";
	
	//api.eventful.com/json/events/search?app_key=X7dwZ7srgVXWD7DB&q=music&l=New+Zealand+Dunedin
	//api.eventful.com/json/events/search?app_key=X7dwZ7srgVXWD7DB&q=Music&l=New+Zealand+Christchurch
	OnTaskResultListener taskListener;
	public interface OnTaskResultListener { public void onResult(ArrayList<Event> in); }
	
	Context context;
	public DataFactory(Context context) {
		this.context = context;
		connectListener();
	}
	
	private void connectListener() {
		try {
            taskListener = (OnTaskResultListener)context;
        } catch (ClassCastException e) {
            throw new ClassCastException("Class must implement OnTaskListener");
        }
	}
	
	public void getEvents(String location, String queryString) {
	
		String URL = API_END_POINT + API_KEY + QUERY_URL + queryString + LOCATION_URL + location;
		new GetEventsTask().execute(URL);
	}
	
	// PRE: No more than 1 URL can be passed in
	private class GetEventsTask extends AsyncTask<String, Void, ArrayList<Event>> {

		@Override
		protected ArrayList<Event> doInBackground(String... urls) {
			
			ArrayList<Event> events = new ArrayList<Event>();

			
			DefaultHttpClient client = new DefaultHttpClient();
			HttpGet httpGet = new HttpGet(urls[0]);
			
			try {
				HttpResponse response = client.execute(httpGet);
				InputStreamReader isr = new InputStreamReader(response.getEntity().getContent());

				JsonParser eventParser = new JsonParser();
				events = eventParser.readInputStream(isr);
				
			} catch (Exception e) {
				e.printStackTrace();
			}		
			
			return events;
		}//End doInBackground

		@Override
		protected void onPostExecute(ArrayList<Event> result) {	
			taskListener.onResult(result);	
		}//End onPostExecute
	}//End GetEventsTask
}
