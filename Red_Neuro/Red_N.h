#pragma once
class Red_N
{
public:
	cv::Ptr<cv::ml::ANN_MLP> red;//Red
	cv::Ptr<cv::ml::TrainData> tData;//Datos de prueba
	int numTrainingpoints = 30;//numero de puntos a entrenar.
	int numTestPoints = 100;//menor que la data para entrenar.
	Red_N();
	Red_N(cv::Mat layers);
	void cargar_data();
	void entrenar();
	void predecir();
	~Red_N();
};

