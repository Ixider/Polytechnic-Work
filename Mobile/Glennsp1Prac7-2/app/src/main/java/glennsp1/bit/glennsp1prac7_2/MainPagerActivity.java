package glennsp1.bit.glennsp1prac7_2;

import android.support.v4.app.Fragment;
import android.support.v4.app.FragmentActivity;
import android.support.v4.app.FragmentManager;
import android.support.v4.app.FragmentPagerAdapter;
import android.support.v4.view.PagerAdapter;
import android.support.v4.view.ViewPager;
import android.support.v7.app.ActionBarActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;

import java.util.ArrayList;


public class MainPagerActivity extends FragmentActivity {

    static final int NUM_PAGES = 2;

    private ViewPager viewPager;
    private PagerAdapter pageAdapter;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        viewPager = (ViewPager)findViewById(R.id.pager);
        pageAdapter = new ScreenPageAdapter(getSupportFragmentManager());
        viewPager.setAdapter(pageAdapter);

    }//End OnCreate

}// End MainPagerActivity

class ScreenPageAdapter extends FragmentPagerAdapter {

    public ScreenPageAdapter(FragmentManager fm) {
        super(fm);
    } // End Constructor

    @Override
    public Fragment getItem(int position) {

        Fragment fragment = null;

        switch(position) {
            case 0:
                fragment =  new SearchFragment();
                break;
            case 1:
                fragment = new TopArtistsFragment();
                break;
            default:
                Log.v("Error", "Fragment selection switch has defaulted");
                break;
        } // End Switch

        return fragment;
    } // End getItem

    @Override
    public int getCount() {
        return MainPagerActivity.NUM_PAGES;
    } // End getCount

    @Override
    public CharSequence getPageTitle(int pos) {
        if(pos  == 0) {
            return "Search";
        } else {
            return "Top Artists";
        }
    } // End getPageTitle
}