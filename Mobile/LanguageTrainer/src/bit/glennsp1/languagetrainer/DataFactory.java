package bit.glennsp1.languagetrainer;
import java.io.IOException;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import org.xmlpull.v1.XmlPullParserException;
import android.content.res.AssetManager;

import bit.glennsp1.languagetrainer.Models.LDataModel;
import bit.glennsp1.languagetrainer.Parsers.GL1_XmlParser;

public class DataFactory  {

	GL1_XmlParser xmlParser;
	AssetManager manager;
	
	public DataFactory(AssetManager sManager) {
		xmlParser = new GL1_XmlParser();
		manager = sManager;
	}
	public List<LDataModel> getData(int lessonNo) throws IOException, XmlPullParserException {
		try{
			InputStream in = manager.open("German.xml");
			List<LDataModel> data = new ArrayList<LDataModel>();
			data = xmlParser.parse(in, lessonNo);
			Collections.shuffle(data);
			return data;
		} finally {
				
		}
	}
}
