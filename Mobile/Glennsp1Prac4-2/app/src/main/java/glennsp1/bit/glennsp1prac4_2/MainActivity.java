package glennsp1.bit.glennsp1prac4_2;


import android.app.Activity;
import android.app.Fragment;
import android.app.FragmentManager;
import android.content.Intent;
import android.os.Bundle;
import android.view.View;


public class MainActivity extends Activity implements ShowListFragment.OnItemSelectedListener{

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        updateUI(-1);
    }

    private void updateUI(int i) {
        FragmentManager fm = getFragmentManager();

        if (findViewById(R.id.fragmentContainer2) == null) {
            fm.beginTransaction().add(R.id.fragmentContainer, new ShowListFragment(), "list_fragment").commit();
        } else {
            Fragment imageFrag = createImageFragment(i);

            fm.beginTransaction()
                    .replace(R.id.fragmentContainer2, imageFrag, "image_fragment")
                    .replace(R.id.fragmentContainer, new ShowListFragment(), "list_fragment")
                    .commit();
        }
    }

    private Fragment createImageFragment(int i) {
        Bundle b = new Bundle();
        b.putInt("picture_id", i);

        Fragment imageFrag = new ShowImageFragment();
        imageFrag.setArguments(b);

        return imageFrag;
    }

    private void createImageActivity(int pos) {
        Intent i = new Intent(getBaseContext(), ActivityB.class);
        i.putExtra("image_id", pos);

        startActivity(i);
    }


    @Override
    public void onItemSelected(int pos) {
        if (findViewById(R.id.fragmentContainer2) == null) {
            createImageActivity(pos);
        }
        updateUI(pos);
    }
}
