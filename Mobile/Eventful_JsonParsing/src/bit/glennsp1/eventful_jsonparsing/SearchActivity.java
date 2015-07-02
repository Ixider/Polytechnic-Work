package bit.glennsp1.eventful_jsonparsing;

import com.example.eventful_jsonparsing.R;
import java.util.ArrayList;
import java.util.Calendar;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.SearchView;
import android.widget.TextView;
import android.widget.Toast;
import android.widget.SearchView.OnQueryTextListener;
import bit.glennsp1.eventful_jsonparsing.DataFactory.OnTaskResultListener;


public class SearchActivity extends Activity implements OnTaskResultListener {

	DataFactory dataFactory;
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_search);
		
		dataFactory = new DataFactory(this);
		
		configureUI();
		
	}//End onCreate

	private void configureUI() {
		((SearchView)findViewById(R.id.eventSearchBar)).setOnQueryTextListener(onQueryTextListener);
	}//End configureUI

	private void getData(String queryString) {
		PrefsManager prefsManager = new PrefsManager(this);
		String location = prefsManager.getLocation();
		
		dataFactory.getEvents(location, queryString);
	}//End getData
	
	OnQueryTextListener onQueryTextListener = new OnQueryTextListener() {
		
		@Override
		public boolean onQueryTextSubmit(String query) {
			getData(query);
			((SearchView)findViewById(R.id.eventSearchBar)).setIconified(true);
			Toast.makeText(getBaseContext(), "Ding", Toast.LENGTH_SHORT);
			return true;
		}
		
		@Override
		public boolean onQueryTextChange(String newText) {
			return false;
		}
		
	};//End OnQueryTextListener
	
	//Receives the Input Stream after DataFactory has completed its AsyncTask
	@Override
	public void onResult(ArrayList<Event> events) {
		ListView v = (ListView)findViewById(R.id.eventListLayout);
		
		EventArrayAdapter adapter = new EventArrayAdapter(this, R.layout.custom_list_view, events);
		
		v.setAdapter(adapter);
		
	}//End onResult
	
	//Action bar methods
	@Override
	public boolean onCreateOptionsMenu(Menu menu) {
		MenuInflater inflater = getMenuInflater();
		inflater.inflate(R.menu.activity_search_menu, menu);
		return super.onCreateOptionsMenu(menu);
	}//End onCreateOptions

	@Override
	public boolean onOptionsItemSelected(MenuItem item) {
		openSettings();
		return super.onOptionsItemSelected(item);
	}//End onOptionsItemSelected
	
	private void openSettings() {
		Intent i = new Intent(this, SettingsActivity.class);
		startActivity(i);
	}//End openSettings
	
	
	public class EventArrayAdapter extends ArrayAdapter<Event> {

		public EventArrayAdapter(Context context, int resource, ArrayList<Event> objects)  {
			super(context, resource, objects);
		}

		@Override
		public View getView(int position, View convertView, ViewGroup container) 
		{
			LayoutInflater layoutInflater = LayoutInflater.from(SearchActivity.this);
			View v = layoutInflater.inflate(R.layout.custom_list_view, container, false);
			
			TextView tv1 = (TextView)v.findViewById(R.id.eTitle);
			TextView tv2 = (TextView)v.findViewById(R.id.eDesc);

			Event currentEvent = this.getItem(position);
			

			tv1.setText(currentEvent.Title);
			tv2.setText(currentEvent.Description);
			
			return v;
		}
		
	 }//End class EventArrayAdapter
}
