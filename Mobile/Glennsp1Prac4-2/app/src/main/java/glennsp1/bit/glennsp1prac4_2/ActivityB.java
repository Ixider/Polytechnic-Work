package glennsp1.bit.glennsp1prac4_2;

import android.app.Activity;
import android.app.Fragment;
import android.app.FragmentManager;
import android.os.Bundle;

/**
 * Created by glenn_000 on 29-Apr-15.
 */
public class ActivityB extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_b);

        int i = getIntent().getIntExtra("image_id", 0);
        FragmentManager fm = getFragmentManager();
        fm.beginTransaction().replace(R.id.fragmentContainer3, createImageFragment(i), "image_fragment").commit();
    }

    private Fragment createImageFragment(int i) {
        Bundle b = new Bundle();
        b.putInt("picture_id", i);

        Fragment imageFrag = new ShowImageFragment();
        imageFrag.setArguments(b);

        return imageFrag;
    }

}
