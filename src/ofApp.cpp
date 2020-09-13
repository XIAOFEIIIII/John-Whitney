#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofSetBackgroundColor(0);
	ofSetLineWidth(5);

	float totalTime = 60;
	float t = min(ofGetElapsedTimef(), totalTime);
	float total_length = 300;
	float A_line = (-6 * total_length) / pow(totalTime, 3);

	float move = (1. / 3)*(A_line*pow(t, 3)) - (1. / 2)*(A_line*totalTime*pow(t, 2));
	float xOrigin_Left = ofGetWidth()*0.5 - total_length + move;
	float xOrigin_Right = ofGetWidth()*0.5 + total_length - move;
	float yOrigin = ofGetHeight()*0.5-50;

	float scale_rtriangle = 10;
	int numTriangle = 16;
	//________LEFT________________________
	for (int i = 1; i <= numTriangle; i++)
	{
		int cycle_id = 2 * i;

		//rotate speed
		int n_cycle = cycle_id;
		float totalAngle = n_cycle * 2*PI;
		float A_angle = ((-6 * totalAngle) / pow(totalTime, 3));
		float rotate = (1. / 3)*(A_angle*pow(t, 3)) - (1. / 2)*(A_angle*totalTime*pow(t, 2));
		
		//r
		float r = cycle_id * scale_rtriangle;
		float a = total_length *cos(30 * PI / 180) ;
		float b = a * tan(30 * PI / 180) ;

		//Right_Moving Ellipse
		float x_Ellipse_Center_Left = xOrigin_Left + a;
		float y_Ellipse_Center_Left = yOrigin;
		//Round_Moving Triangle(Center+Drawline)
		float x_Triange_Center_Left = x_Ellipse_Center_Left - a * cos(rotate);
		float y_Triange_Center_Left = y_Ellipse_Center_Left + b * sin(rotate);

		float x_Triange_Left_Left  = x_Triange_Center_Left - r * cos(30 * PI / 180);
		float x_Triange_Left_Right = x_Triange_Center_Left + r * cos(30 * PI / 180);
		float x_Triange_Left_Down  = x_Triange_Center_Left;

		float y_Triange_Left_Left  = y_Triange_Center_Left - r * sin(30 * PI / 180);
		float y_Triange_Left_Right = y_Triange_Center_Left - r * sin(30 * PI / 180);
		float y_Triange_Left_Down  = y_Triange_Center_Left + r;

		// ofDrawCircle(x_Triange_Center_Left, y_Triange_Center_Left, 5);

		ofSetColor(255, 240, 240);
		ofDrawCircle(x_Triange_Left_Left, y_Triange_Left_Left, 2.5);
		ofDrawCircle(x_Triange_Left_Right, y_Triange_Left_Right, 2.5);
		ofDrawCircle(x_Triange_Left_Down, y_Triange_Left_Down, 2.5);

		ofDrawLine(x_Triange_Left_Left, y_Triange_Left_Left, x_Triange_Left_Right, y_Triange_Left_Right);
		ofDrawLine(x_Triange_Left_Left, y_Triange_Left_Left, x_Triange_Left_Down, y_Triange_Left_Down);
		ofDrawLine(x_Triange_Left_Right, y_Triange_Left_Right, x_Triange_Left_Down, y_Triange_Left_Down);

	}
	//________RIGHT________________________
	for (int i = 1; i <= numTriangle; i++)
	{
		int cycle_id = 2 * i-1;

		//rotate speed
		int n_cycle = cycle_id;
		float totalAngle = n_cycle * 2* PI;
		float A_angle =((-6 * totalAngle) / pow(totalTime, 3));
		float rotate = (1. / 3)*(A_angle*pow(t, 3)) - (1. / 2)*(A_angle*totalTime*pow(t, 2));

		//r
		float r = cycle_id * scale_rtriangle;
		float a = total_length * cos(30 * PI / 180);
		float b = a * tan(30 * PI / 180);
		//Left_Moving Ellipse
		float x_Ellipse_Center_Right = xOrigin_Right - a;
		float y_Ellipse_Center_Right = yOrigin;
		//Round_Moving Triangle(Center+Drawline)
		float x_Triange_Center_Right = x_Ellipse_Center_Right + a * cos(rotate);
		float y_Triange_Center_Right = y_Ellipse_Center_Right + b * sin(rotate);

		float x_Triange_Right_Left = x_Triange_Center_Right - r * cos(30 * PI / 180);
		float x_Triange_Right_Right = x_Triange_Center_Right + r * cos(30 * PI / 180);
		float x_Triange_Right_Down = x_Triange_Center_Right;

		float y_Triange_Right_Left = y_Triange_Center_Right - r * sin(30 * PI / 180);
		float y_Triange_Right_Right = y_Triange_Center_Right - r * sin(30 * PI / 180);
		float y_Triange_Right_Down = y_Triange_Center_Right + r;

		// ofDrawCircle(x_Triange_Center_Left, y_Triange_Center_Left, 5);

		
		ofSetColor(100, 0, 0);
		ofDrawCircle(x_Triange_Right_Left, y_Triange_Right_Left, 2.5);
		ofDrawCircle(x_Triange_Right_Right, y_Triange_Right_Right, 2.5);
		ofDrawCircle(x_Triange_Right_Down, y_Triange_Right_Down, 2.5);

		ofDrawLine(x_Triange_Right_Left, y_Triange_Right_Left, x_Triange_Right_Right, y_Triange_Right_Right);
		ofDrawLine(x_Triange_Right_Left, y_Triange_Right_Left, x_Triange_Right_Down, y_Triange_Right_Down);
		ofDrawLine(x_Triange_Right_Right, y_Triange_Right_Right, x_Triange_Right_Down, y_Triange_Right_Down);

	}

	
	

	/*float T = 5;
	int r = 150;
	int n_cycle = 1;
	float totalAngle = n_cycle * 2*PI;
	float A_angle = (-6 * totalAngle) / pow(T, 3);
	float total_length = 130;
	
	float t = min(ofGetElapsedTimef(), T);

	float a = r* cos(30 * PI / 180);
	float b = a * tan(30 * PI / 180);

	float move = (1. / 3)*(A_line*pow(t, 3)) - (1. / 2)*(A_line*T*pow(t, 2));
	float rotate = (1. / 3)*(A_angle*pow(t, 3)) - (1. / 2)*(A_angle*T*pow(t, 2));

	float x1orig = ofGetWidth()*0.5  - r * cos(30*PI/180)- total_length + move;
	float y1orig = ofGetHeight()*0.5 - r * sin(30 * PI / 180);

	float x2orig = ofGetWidth()*0.5  + r * cos(30 * PI / 180) - total_length + move;
	float y2orig = ofGetHeight()*0.5 - r * sin(30 * PI / 180);

	float x3orig = ofGetWidth()*0.5 - total_length + move;
	float y3orig = ofGetHeight()*0.5 + r * cos(30 * PI / 180);*/

	

	//float angle = 0.05*(a*pow(t, 2) - a * T*t);
	
	/*float x1 = x1orig + a * cos(rotate);
	float y1 = y1orig + b * sin(rotate);

	float x2 = x2orig + a * cos(rotate);
	float y2 = y2orig + b * sin(rotate);

	float x3 = x3orig + a * cos(rotate);
	float y3 = y3orig + b * sin(rotate);*/

	/*ofSetColor(255, 0, 0);
	ofDrawLine(x1, y1, x2, y2);
	ofDrawLine(x1, y1, x3, y3);
	ofDrawLine(x2, y2, x3, y3);
	ofDrawCircle(x1orig, y1orig, 5);*/

	/*trail.addVertex(x1, y1);
	trail.addVertex(x2, y2);
	trail.addVertex(x3, y3);*/


}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
