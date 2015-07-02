package glennsp1.bit.thirdrdpartylibraries.ImageExplodeAnimation;

import android.app.Fragment;
import android.graphics.drawable.Drawable;
import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v4.content.res.ResourcesCompat;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.view.animation.Animation;
import android.widget.Button;
import android.widget.FrameLayout;
import android.widget.ImageView;

import com.easyandroidanimations.library.AnimationListener;
import com.easyandroidanimations.library.ExplodeAnimation;

import glennsp1.bit.thirdrdpartylibraries.R;

/**
 * Created by S. Glenn on 07-May-15.
 */
public class ExplodeAnimationFragment extends Fragment {

    ImageView mImageView;
    boolean mAnimationInprogress;
    @Nullable
    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        View v = inflater.inflate(R.layout.fragment_image_animation_layout, container, false);

        init(v);

        return v;
    }

    private void init(View v) {
        Button animateBtn = (Button)v.findViewById(R.id.animation_button);
        animateBtn.setOnClickListener(new onClickListener());

        mImageView = (ImageView)v.findViewById(R.id.animation_image);

        mAnimationInprogress = false;
    }


    class onClickListener implements View.OnClickListener {

        @Override
        public void onClick(View view) {

            ImageView imageView = mImageView;

            if(!mAnimationInprogress) {
                mAnimationInprogress = true;

                ExplodeAnimation explodeAnimation = new ExplodeAnimation(imageView);
                explodeAnimation.setDuration(500);
                explodeAnimation.setListener(new animationListener());
                explodeAnimation.animate();

            }
        }

    }//End onClickListener

    class animationListener implements AnimationListener {

        @Override
        public void onAnimationEnd(com.easyandroidanimations.library.Animation animation) {
            mAnimationInprogress = false;
            resetImage();
        }
    }


    private void resetImage() {

        FrameLayout frameLayout = (FrameLayout)getActivity().findViewById(R.id.image_frame);
        frameLayout.removeView(mImageView);

        LayoutInflater inflater = getActivity().getLayoutInflater();
        mImageView = (ImageView) inflater.inflate(R.layout.view_image_view, frameLayout, false);

        frameLayout.addView(mImageView);
    }
}
