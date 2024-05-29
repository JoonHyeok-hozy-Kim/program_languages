package ch_10.objects.MockObject;

public interface IGradeBook {
    void addScore(int studentId, double score);
    double getAverageScore(int studentId);
    void save(String filename);
}
