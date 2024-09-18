using namespace std; 

//���� 
class CarFromManufacturer {
private:
    string model;          // �ͺ� 
    string manufacturer;   // ������ 
    string productionDate; // �������� 
    int warrantyYears;          // ������

public:
    CarFromManufacturer(string m, string mf, string pd, int wy) 
        : model(m), manufacturer(mf), productionDate(pd), warrantyYears(wy) {}

    string getModel() const { return model; }
    string getManufacturer() const { return manufacturer; }
    string getProductionDate() const { return productionDate; }

    bool isUnderWarranty() const {
        return warrantyYears > 0;
    }

    void repair() {
        cout << "Repairing on car: " << model << endl;
    }
};

//����
 class CarFromOwner {
 private:
     string licensePlate;  // ���ƺ�
     double miles;            // ��ʻ���
     string fuelType;      // ��������
     bool isInsured;            // �Ƿ��б��� 
 
 public:
     CarFromOwner(string lp, double m, string ft, bool insured)
         : licensePlate(lp), mileage(m), fuelType(ft), isInsured(insured) {}
 
     string getLicensePlate() const { return licensePlate; }
     double getMiles() const { return miles; }
 
     void drive(double distance) {
         mileage += distance;
         cout << "Car driven for " << distance << " km. Total mileage: " << mileage << " km." << endl;
     }
 
     bool checkInsurance() const { return isInsured; }
 
     void renewInsurance() { isInsured = true; }
 };
 
 //��ͨ�������
  class CarFromTrafficAuthority {
  private:
      string registrationNumber;  // �ǼǺ�
      string ownerName;           // ��������
      string registrationDate;    // �Ǽ�����
      bool passedInspection;           // ���
  
  public:
      CarFromTrafficAuthority(string rn, string on, string rd, bool pi) 
          : registrationNumber(rn), ownerName(on), registrationDate(rd), passedInspection(pi) {}
  
      string getRegistrationNumber() const { return registrationNumber; }
      string getOwnerName() const { return ownerName; }
  
      bool isInspectionPassed() const { return passedInspection; }
  
      void updateInspectionStatus(bool status) {
          passedInspection = status;
          cout << "Inspection status updated: " << (status ? "Passed" : "Not Passed") << endl;
      }
  };
  
