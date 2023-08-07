#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetWindowTitle("openFrameworks");

	ofBackground(39);
	ofSetColor(255, 64);

	ofNoFill();
	ofSetCircleResolution(72);
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
	ofSetLineWidth(2);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	for (int x = -230; x <= 230; x += 230) {

		for (int y = -230; y <= 230; y += 230) {

			glm::vec3 noise_seed = glm::vec3(ofRandom(1000), ofRandom(1000), ofRandom(1000));
			for (int i = 0; i < 30; i++) {

				ofPushMatrix();
				ofTranslate(x, y);

				ofRotateZ(ofMap(ofNoise(noise_seed.z, i * 0.0085 + ofGetFrameNum() * 0.005), 0, 1, -180, 180));
				ofRotateY(ofMap(ofNoise(noise_seed.y, i * 0.0085 + ofGetFrameNum() * 0.005), 0, 1, -180, 180));
				ofRotateX(ofMap(ofNoise(noise_seed.x, i * 0.0085 + ofGetFrameNum() * 0.005), 0, 1, -180, 180));

				ofDrawCircle(glm::vec2(), 100);

				ofPopMatrix();
			}
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}