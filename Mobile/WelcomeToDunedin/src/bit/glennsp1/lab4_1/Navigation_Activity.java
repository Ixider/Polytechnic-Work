package bit.glennsp1.lab4_1;

import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.Currency;
import java.util.List;

import bit.glennsp1.lab4_1.DataModels.NavItem;

import android.app.Activity;
import android.app.Fragment;
import android.app.FragmentManager;
import android.app.FragmentTransaction;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.AdapterView.OnItemClickListener;
import android.widget.ArrayAdapter;
import android.widget.ListView;
import android.widget.TextView;

public class Navigation_Activity extends Activity {

	private List<NavItem> navItems;
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.nav_draw);
		
		navItems = getListItems();
		ListView drawerList = (ListView)findViewById(R.id.left_drawer);
		
		drawerList.setAdapter(new ArrayAdapter<String>(this, android.R.layout.simple_list_item_1, extractTitles()));
		drawerList.setOnItemClickListener(onItemClickListener);
		
		loadMainScreen();
	}//End onCreate
	
	private List<NavItem> getListItems() {
		List<NavItem> ni = new ArrayList<NavItem>();
		try {
			InputStream in = getAssets().open("nav_items.txt");
			JsonParser jp = new JsonParser();
			ni = jp.readJsonStream(in);
		} catch (IOException e) {
			e.printStackTrace();
		}	
		return ni;
	}//End getListItems
	
	//Extracts titles from parsed json to be displayed my the navagation drawer adapter
	private List<String> extractTitles() {
		List<String> titles = new ArrayList<String>();
		for(int i = 0; i < navItems.size(); i++)
			titles.add(navItems.get(i).Title);
		return titles;
	}//End extractTitles
	
	// Starts main screen fragment for 
	private void loadMainScreen() {
		startFramgnet("Welcome to Dunedin", "big_octagon", false);
	}//End loadMainScreen()
	
	//Starts a new fragment with givent information to be display to user
	private void startFramgnet(String Title, String ImageName, boolean addToBackStack) {
		FragmentManager fm = getFragmentManager();		
	
			Fragment contentFragment = new Content_DIsplay_Fragment();
			
			Bundle bundle = new Bundle();
			bundle.putString("TITLE", Title);
			bundle.putString("IMAGE_NAME", ImageName);
			
			contentFragment.setArguments(bundle);
			
			FragmentTransaction ft = fm.beginTransaction();
			
			if(addToBackStack) 
				ft.addToBackStack(Title);
			
			ft.setCustomAnimations(R.anim.right_in, R.anim.left_out, R.anim.right_in, R.anim.left_out);
			ft.add(R.id.content_frame, contentFragment, Title);
			
			ft.commit();		
	}//End startFragment
	
	// Handles user clicking on an item on the navagation drawer
	OnItemClickListener onItemClickListener = new OnItemClickListener() {

		@Override
		public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
			String title = navItems.get(position).Title;
			String imageName = navItems.get(position).ImageName;
			
			Fragment curFrag = getFragmentManager().findFragmentByTag(title);
			// When current fragment is not null it  means the user already has this fragment in the back stack
			if(curFrag == null)
				startFramgnet(title, imageName, true);	
		}
	};//End onItemClickListener	
}
