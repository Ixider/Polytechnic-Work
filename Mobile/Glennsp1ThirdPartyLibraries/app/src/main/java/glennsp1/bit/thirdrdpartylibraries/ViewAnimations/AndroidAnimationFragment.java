package glennsp1.bit.thirdrdpartylibraries.ViewAnimations;

import android.app.Fragment;
import android.os.Bundle;
import android.support.annotation.Nullable;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.FrameLayout;
import android.widget.ImageView;


import com.daimajia.androidanimations.library.Techniques;
import com.daimajia.androidanimations.library.YoYo;

import glennsp1.bit.thirdrdpartylibraries.R;

/**
 * Created by S. Glenn on 10-May-15.
 */
public class AndroidAnimationFragment extends Fragment {

    ImageView mImageView;
    FrameLayout mFrameLayout;

    @Nullable
    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {

        View v = inflater.inflate(R.layout.fragment_image_animation_layout, container, false);

        init(v);

        return v;
    }//End onCreateView

    private void init(View v) {

        Button button = (Button)v.findViewById(R.id.animation_button);
        button.setOnClickListener(new onClickListener());

        ImageView imageView = (ImageView)v.findViewById(R.id.animation_image);

        mFrameLayout = (FrameLayout) v.findViewById(R.id.image_frame);
        mFrameLayout.removeView(imageView);

        inflateNewImage();

    }//End init


    class onClickListener implements View.OnClickListener {

        @Override
        public void onClick(View view) {
            YoYo.with(Techniques.StandUp).duration(500).playOn(mImageView);
        }
    }

    private void inflateNewImage() {
        mFrameLayout.removeView(mImageView);
        LayoutInflater inflater = getActivity().getLayoutInflater();

        mImageView = (ImageView)inflater.inflate(R.layout.view_image_view, mFrameLayout, false);

        mFrameLayout.addView(mImageView);
    }

}
