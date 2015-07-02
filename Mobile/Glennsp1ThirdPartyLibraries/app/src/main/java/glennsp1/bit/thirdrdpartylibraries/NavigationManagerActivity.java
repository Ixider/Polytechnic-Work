package glennsp1.bit.thirdrdpartylibraries;

import android.app.Activity;
import android.app.Fragment;
import android.app.FragmentManager;
import android.app.FragmentTransaction;
import android.content.res.Resources;
import android.os.Bundle;
import android.support.v4.widget.DrawerLayout;
import android.support.v7.app.ActionBarDrawerToggle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;
import android.view.Gravity;
import android.view.MenuItem;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;

import com.google.android.gms.maps.GoogleMap;
import com.google.android.gms.maps.MapFragment;

import glennsp1.bit.thirdrdpartylibraries.GoogleMap.FragmentGoogleMaps;
import glennsp1.bit.thirdrdpartylibraries.ImageExplodeAnimation.ExplodeAnimationFragment;
import glennsp1.bit.thirdrdpartylibraries.RippleBackground.FragmentRippleBackground;
import glennsp1.bit.thirdrdpartylibraries.ViewAnimations.AndroidAnimationFragment;


public class NavigationManagerActivity extends AppCompatActivity {

    public  enum mFragmentType { RIPPLE_BACKGROUND, EXPLODE_ANIMATION, VIEW_ANIMATIONS, GOOGLE_MAP }

    private ActionBarDrawerToggle mDrawerToggle;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_navigation_manager_layout);

        init();
    }

    private void init() {

        setUpActionBar();
        setUpNavDrawer();

        String[] nav_items = getResources().getStringArray(R.array.ActivityList);

        ListView nav_list = (ListView) findViewById(R.id.left_drawer);

        nav_list.setAdapter(new ArrayAdapter<>(this, android.R.layout.simple_list_item_1, nav_items));

        nav_list.setOnItemClickListener(onNavItemCLick);
    }

    private void setUpActionBar() {
        getSupportActionBar().setDisplayHomeAsUpEnabled(true);
        getSupportActionBar().setHomeButtonEnabled(true);
    }

    private void setUpNavDrawer() {
        DrawerLayout drawerLayout = (DrawerLayout) findViewById(R.id.drawer_layout);
        drawerLayout.setDrawerShadow(R.drawable.drawer_shadow, Gravity.START);

        mDrawerToggle = new MyToggleClass(this, drawerLayout, R.string.drawer_nav_open, R.string.app_name);

        mDrawerToggle.setDrawerIndicatorEnabled(true);
        drawerLayout.setDrawerListener(mDrawerToggle);
        mDrawerToggle.syncState();
    }

    private class MyToggleClass extends ActionBarDrawerToggle {

        public MyToggleClass(Activity activity, DrawerLayout drawerLayout, int openDrawerContentDescRes, int closeDrawerContentDescRes) {
            super(activity, drawerLayout, openDrawerContentDescRes, closeDrawerContentDescRes);
        }

        @Override
        public void onDrawerOpened(View drawerView) {
            super.onDrawerOpened(drawerView);
            invalidateOptionsMenu(); // creates call to onPrepareOptionsMenu()
        }

        @Override
        public void onDrawerClosed(View drawerView) {
            super.onDrawerClosed(drawerView);
            invalidateOptionsMenu();
        }
    }


    private void startFragment(Fragment fragment, String id) {
        if(fragment != null) {
            FragmentManager fm = getFragmentManager();
            FragmentTransaction ft = fm.beginTransaction();
            ft.replace(R.id.contentFrame, fragment, id);
            ft.commit();
        }
    }


    //Handles nav drawer list item selection input
    AdapterView.OnItemClickListener onNavItemCLick = new AdapterView.OnItemClickListener() {

        @Override
        public void onItemClick(AdapterView<?> adapterView, View view, int i, long l) {

            Fragment fragment = null;

            mFragmentType fragmentType = mFragmentType.values()[i];

            switch (fragmentType) {
                case RIPPLE_BACKGROUND:
                    fragment = new FragmentRippleBackground();
                    break;
                case EXPLODE_ANIMATION:
                    fragment = new ExplodeAnimationFragment();
                    break;
                case VIEW_ANIMATIONS:
                    fragment = new AndroidAnimationFragment();
                    break;

                case GOOGLE_MAP:
                    fragment = new FragmentGoogleMaps();
                    break;
                default:
                    Log.v("NAV", "Nav item on click switch defaulted");
                    break;
            }

            closeDrawer();
            startFragment(fragment, Integer.toString(i));
        }
    };//End onNavItemClick

    private void closeDrawer() {
        DrawerLayout drawerLayout = (DrawerLayout)findViewById(R.id.drawer_layout);
        drawerLayout.closeDrawers();
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {

        if (mDrawerToggle.onOptionsItemSelected(item)) {
            return true;
        }

        return super.onOptionsItemSelected(item);
    }
}
