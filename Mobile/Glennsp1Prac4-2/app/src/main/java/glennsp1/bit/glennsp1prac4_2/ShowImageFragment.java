package glennsp1.bit.glennsp1prac4_2;

import android.app.Fragment;
import android.os.Bundle;
import android.support.annotation.Nullable;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.Toast;

/**
 * Created by glenn_000 on 29-Apr-15.
 */
public class ShowImageFragment extends Fragment {



    @Override
    public View onCreateView(LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        View v = inflater.inflate(R.layout.show_an_image_fragment, container, false);

        int i = getArguments().getInt("picture_id");
        switch (i) {
            case 0:
                ((ImageView)v.findViewById(R.id.imageView1)).setImageDrawable(getResources().getDrawable(R.drawable.sheep));
                break;
            case 1:
                ((ImageView)v.findViewById(R.id.imageView1)).setImageDrawable(getResources().getDrawable(R.drawable.cow));
                break;
            default:
                ((ImageView)v.findViewById(R.id.imageView1)).setImageDrawable(null);
                Toast.makeText(getActivity(), "No Image", Toast.LENGTH_LONG).show();
                break;
        }

        return v;
    }
}
