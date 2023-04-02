<?xml version="1.0" encoding="UTF-8"?>
<model ref="r:3a3dd9db-dea6-4882-95eb-b899e517d5c8(mealyFSM.generator01.templates@generator)">
  <persistence version="9" />
  <languages>
    <use id="b401a680-8325-4110-8fd3-84331ff25bef" name="jetbrains.mps.lang.generator" version="4" />
    <devkit ref="a2eb3a43-fcc2-4200-80dc-c60110c4862d(jetbrains.mps.devkit.templates)" />
  </languages>
  <imports>
    <import index="gob8" ref="r:373d6e1c-0570-4758-801e-9091d69134c1(mealyFSM.structure)" />
    <import index="guwi" ref="6354ebe7-c22a-4a0f-ac54-50b52ab9b065/java:java.io(JDK/)" />
    <import index="wyt6" ref="6354ebe7-c22a-4a0f-ac54-50b52ab9b065/java:java.lang(JDK/)" />
    <import index="tpck" ref="r:00000000-0000-4000-0000-011c89590288(jetbrains.mps.lang.core.structure)" />
  </imports>
  <registry>
    <language id="f3061a53-9226-4cc5-a443-f952ceaf5816" name="jetbrains.mps.baseLanguage">
      <concept id="1215693861676" name="jetbrains.mps.baseLanguage.structure.BaseAssignmentExpression" flags="nn" index="d038R">
        <child id="1068498886297" name="rValue" index="37vLTx" />
        <child id="1068498886295" name="lValue" index="37vLTJ" />
      </concept>
      <concept id="1202948039474" name="jetbrains.mps.baseLanguage.structure.InstanceMethodCallOperation" flags="nn" index="liA8E" />
      <concept id="1465982738277781862" name="jetbrains.mps.baseLanguage.structure.PlaceholderMember" flags="nn" index="2tJIrI" />
      <concept id="1197027756228" name="jetbrains.mps.baseLanguage.structure.DotExpression" flags="nn" index="2OqwBi">
        <child id="1197027771414" name="operand" index="2Oq$k0" />
        <child id="1197027833540" name="operation" index="2OqNvi" />
      </concept>
      <concept id="1197029447546" name="jetbrains.mps.baseLanguage.structure.FieldReferenceOperation" flags="nn" index="2OwXpG">
        <reference id="1197029500499" name="fieldDeclaration" index="2Oxat5" />
      </concept>
      <concept id="1145552977093" name="jetbrains.mps.baseLanguage.structure.GenericNewExpression" flags="nn" index="2ShNRf">
        <child id="1145553007750" name="creator" index="2ShVmc" />
      </concept>
      <concept id="1137021947720" name="jetbrains.mps.baseLanguage.structure.ConceptFunction" flags="in" index="2VMwT0">
        <child id="1137022507850" name="body" index="2VODD2" />
      </concept>
      <concept id="1070475354124" name="jetbrains.mps.baseLanguage.structure.ThisExpression" flags="nn" index="Xjq3P" />
      <concept id="1070475926800" name="jetbrains.mps.baseLanguage.structure.StringLiteral" flags="nn" index="Xl_RD">
        <property id="1070475926801" name="value" index="Xl_RC" />
      </concept>
      <concept id="1081236700938" name="jetbrains.mps.baseLanguage.structure.StaticMethodDeclaration" flags="ig" index="2YIFZL" />
      <concept id="1070533707846" name="jetbrains.mps.baseLanguage.structure.StaticFieldReference" flags="nn" index="10M0yZ">
        <reference id="1144433057691" name="classifier" index="1PxDUh" />
      </concept>
      <concept id="1070534370425" name="jetbrains.mps.baseLanguage.structure.IntegerType" flags="in" index="10Oyi0" />
      <concept id="1070534760951" name="jetbrains.mps.baseLanguage.structure.ArrayType" flags="in" index="10Q1$e">
        <child id="1070534760952" name="componentType" index="10Q1$1" />
      </concept>
      <concept id="1068390468200" name="jetbrains.mps.baseLanguage.structure.FieldDeclaration" flags="ig" index="312cEg" />
      <concept id="1068390468198" name="jetbrains.mps.baseLanguage.structure.ClassConcept" flags="ig" index="312cEu" />
      <concept id="1068431474542" name="jetbrains.mps.baseLanguage.structure.VariableDeclaration" flags="ng" index="33uBYm">
        <property id="1176718929932" name="isFinal" index="3TUv4t" />
        <child id="1068431790190" name="initializer" index="33vP2m" />
      </concept>
      <concept id="1068498886296" name="jetbrains.mps.baseLanguage.structure.VariableReference" flags="nn" index="37vLTw">
        <reference id="1068581517664" name="variableDeclaration" index="3cqZAo" />
      </concept>
      <concept id="1068498886292" name="jetbrains.mps.baseLanguage.structure.ParameterDeclaration" flags="ir" index="37vLTG" />
      <concept id="1068498886294" name="jetbrains.mps.baseLanguage.structure.AssignmentExpression" flags="nn" index="37vLTI" />
      <concept id="4972933694980447171" name="jetbrains.mps.baseLanguage.structure.BaseVariableDeclaration" flags="ng" index="19Szcq">
        <child id="5680397130376446158" name="type" index="1tU5fm" />
      </concept>
      <concept id="1068580123132" name="jetbrains.mps.baseLanguage.structure.BaseMethodDeclaration" flags="ng" index="3clF44">
        <child id="1068580123133" name="returnType" index="3clF45" />
        <child id="1068580123134" name="parameter" index="3clF46" />
        <child id="1068580123135" name="body" index="3clF47" />
      </concept>
      <concept id="1068580123165" name="jetbrains.mps.baseLanguage.structure.InstanceMethodDeclaration" flags="ig" index="3clFb_" />
      <concept id="1068580123155" name="jetbrains.mps.baseLanguage.structure.ExpressionStatement" flags="nn" index="3clFbF">
        <child id="1068580123156" name="expression" index="3clFbG" />
      </concept>
      <concept id="1068580123136" name="jetbrains.mps.baseLanguage.structure.StatementList" flags="sn" stub="5293379017992965193" index="3clFbS">
        <child id="1068581517665" name="statement" index="3cqZAp" />
      </concept>
      <concept id="1068580123140" name="jetbrains.mps.baseLanguage.structure.ConstructorDeclaration" flags="ig" index="3clFbW" />
      <concept id="1068580320020" name="jetbrains.mps.baseLanguage.structure.IntegerConstant" flags="nn" index="3cmrfG">
        <property id="1068580320021" name="value" index="3cmrfH" />
      </concept>
      <concept id="1068581242875" name="jetbrains.mps.baseLanguage.structure.PlusExpression" flags="nn" index="3cpWs3" />
      <concept id="1068581242864" name="jetbrains.mps.baseLanguage.structure.LocalVariableDeclarationStatement" flags="nn" index="3cpWs8">
        <child id="1068581242865" name="localVariableDeclaration" index="3cpWs9" />
      </concept>
      <concept id="1068581242863" name="jetbrains.mps.baseLanguage.structure.LocalVariableDeclaration" flags="nr" index="3cpWsn" />
      <concept id="1068581517677" name="jetbrains.mps.baseLanguage.structure.VoidType" flags="in" index="3cqZAl" />
      <concept id="1204053956946" name="jetbrains.mps.baseLanguage.structure.IMethodCall" flags="ng" index="1ndlxa">
        <reference id="1068499141037" name="baseMethodDeclaration" index="37wK5l" />
        <child id="1068499141038" name="actualArgument" index="37wK5m" />
      </concept>
      <concept id="1212685548494" name="jetbrains.mps.baseLanguage.structure.ClassCreator" flags="nn" index="1pGfFk" />
      <concept id="1107461130800" name="jetbrains.mps.baseLanguage.structure.Classifier" flags="ng" index="3pOWGL">
        <child id="5375687026011219971" name="member" index="jymVt" unordered="true" />
      </concept>
      <concept id="1107535904670" name="jetbrains.mps.baseLanguage.structure.ClassifierType" flags="in" index="3uibUv">
        <reference id="1107535924139" name="classifier" index="3uigEE" />
      </concept>
      <concept id="1081773326031" name="jetbrains.mps.baseLanguage.structure.BinaryOperation" flags="nn" index="3uHJSO">
        <child id="1081773367579" name="rightExpression" index="3uHU7w" />
        <child id="1081773367580" name="leftExpression" index="3uHU7B" />
      </concept>
      <concept id="1081855346303" name="jetbrains.mps.baseLanguage.structure.BreakStatement" flags="nn" index="3zACq4" />
      <concept id="1178549954367" name="jetbrains.mps.baseLanguage.structure.IVisible" flags="ng" index="1B3ioH">
        <child id="1178549979242" name="visibility" index="1B3o_S" />
      </concept>
      <concept id="1163670490218" name="jetbrains.mps.baseLanguage.structure.SwitchStatement" flags="nn" index="3KaCP$">
        <child id="1163670766145" name="expression" index="3KbGdf" />
        <child id="1163670772911" name="case" index="3KbHQx" />
      </concept>
      <concept id="1163670641947" name="jetbrains.mps.baseLanguage.structure.SwitchCase" flags="ng" index="3KbdKl">
        <child id="1163670677455" name="expression" index="3Kbmr1" />
        <child id="1163670683720" name="body" index="3Kbo56" />
      </concept>
      <concept id="1146644602865" name="jetbrains.mps.baseLanguage.structure.PublicVisibility" flags="nn" index="3Tm1VV" />
      <concept id="1146644623116" name="jetbrains.mps.baseLanguage.structure.PrivateVisibility" flags="nn" index="3Tm6S6" />
    </language>
    <language id="b401a680-8325-4110-8fd3-84331ff25bef" name="jetbrains.mps.lang.generator">
      <concept id="1095416546421" name="jetbrains.mps.lang.generator.structure.MappingConfiguration" flags="ig" index="bUwia">
        <child id="1167514678247" name="rootMappingRule" index="3lj3bC" />
      </concept>
      <concept id="1168619357332" name="jetbrains.mps.lang.generator.structure.RootTemplateAnnotation" flags="lg" index="n94m4">
        <reference id="1168619429071" name="applicableConcept" index="n9lRv" />
      </concept>
      <concept id="1167169188348" name="jetbrains.mps.lang.generator.structure.TemplateFunctionParameter_sourceNode" flags="nn" index="30H73N" />
      <concept id="1167169308231" name="jetbrains.mps.lang.generator.structure.BaseMappingRule" flags="ng" index="30H$t8">
        <reference id="1167169349424" name="applicableConcept" index="30HIoZ" />
      </concept>
      <concept id="1087833241328" name="jetbrains.mps.lang.generator.structure.PropertyMacro" flags="ln" index="17Uvod">
        <child id="1167756362303" name="propertyValueFunction" index="3zH0cK" />
      </concept>
      <concept id="1167514355419" name="jetbrains.mps.lang.generator.structure.Root_MappingRule" flags="lg" index="3lhOvk">
        <reference id="1167514355421" name="template" index="3lhOvi" />
      </concept>
      <concept id="1167756080639" name="jetbrains.mps.lang.generator.structure.PropertyMacro_GetPropertyValue" flags="in" index="3zFVjK" />
      <concept id="1167770111131" name="jetbrains.mps.lang.generator.structure.ReferenceMacro_GetReferent" flags="in" index="3$xsQk" />
      <concept id="1167951910403" name="jetbrains.mps.lang.generator.structure.SourceSubstituteMacro_SourceNodesQuery" flags="in" index="3JmXsc" />
      <concept id="1118786554307" name="jetbrains.mps.lang.generator.structure.LoopMacro" flags="ln" index="1WS0z7">
        <child id="1167952069335" name="sourceNodesQuery" index="3Jn$fo" />
      </concept>
      <concept id="1088761943574" name="jetbrains.mps.lang.generator.structure.ReferenceMacro" flags="ln" index="1ZhdrF">
        <child id="1167770376702" name="referentFunction" index="3$ytzL" />
      </concept>
    </language>
    <language id="7866978e-a0f0-4cc7-81bc-4d213d9375e1" name="jetbrains.mps.lang.smodel">
      <concept id="1179168000618" name="jetbrains.mps.lang.smodel.structure.Node_GetIndexInParentOperation" flags="nn" index="2bSWHS" />
      <concept id="1138056022639" name="jetbrains.mps.lang.smodel.structure.SPropertyAccess" flags="nn" index="3TrcHB">
        <reference id="1138056395725" name="property" index="3TsBF5" />
      </concept>
      <concept id="1138056143562" name="jetbrains.mps.lang.smodel.structure.SLinkAccess" flags="nn" index="3TrEf2">
        <reference id="1138056516764" name="link" index="3Tt5mk" />
      </concept>
      <concept id="1138056282393" name="jetbrains.mps.lang.smodel.structure.SLinkListAccess" flags="nn" index="3Tsc0h">
        <reference id="1138056546658" name="link" index="3TtcxE" />
      </concept>
    </language>
    <language id="ceab5195-25ea-4f22-9b92-103b95ca8c0c" name="jetbrains.mps.lang.core">
      <concept id="1133920641626" name="jetbrains.mps.lang.core.structure.BaseConcept" flags="ng" index="2VYdi">
        <child id="5169995583184591170" name="smodelAttribute" index="lGtFl" />
      </concept>
      <concept id="3364660638048049750" name="jetbrains.mps.lang.core.structure.PropertyAttribute" flags="ng" index="A9Btg">
        <property id="1757699476691236117" name="name_DebugInfo" index="2qtEX9" />
        <property id="1341860900487648621" name="propertyId" index="P4ACc" />
      </concept>
      <concept id="3364660638048049745" name="jetbrains.mps.lang.core.structure.LinkAttribute" flags="ng" index="A9Btn">
        <property id="1757699476691236116" name="role_DebugInfo" index="2qtEX8" />
        <property id="1341860900488019036" name="linkId" index="P3scX" />
      </concept>
      <concept id="1169194658468" name="jetbrains.mps.lang.core.structure.INamedConcept" flags="ng" index="TrEIO">
        <property id="1169194664001" name="name" index="TrG5h" />
      </concept>
      <concept id="709746936026466394" name="jetbrains.mps.lang.core.structure.ChildAttribute" flags="ng" index="3VBwX9">
        <property id="709746936026609031" name="linkId" index="3V$3ak" />
        <property id="709746936026609029" name="role_DebugInfo" index="3V$3am" />
      </concept>
      <concept id="4452961908202556907" name="jetbrains.mps.lang.core.structure.BaseCommentAttribute" flags="ng" index="1X3_iC">
        <child id="3078666699043039389" name="commentedNode" index="8Wnug" />
      </concept>
    </language>
  </registry>
  <node concept="bUwia" id="L$vW9Ug0S2">
    <property role="TrG5h" value="main" />
    <node concept="3lhOvk" id="L$vW9Ug0U_" role="3lj3bC">
      <ref role="3lhOvi" node="L$vW9Ug0UE" resolve="Main" />
      <ref role="30HIoZ" to="gob8:3keuZSaMt2L" resolve="StateMachine" />
    </node>
    <node concept="3lhOvk" id="L$vW9Ug0UB" role="3lj3bC">
      <ref role="30HIoZ" to="gob8:3keuZSaMt2L" resolve="StateMachine" />
      <ref role="3lhOvi" node="6uB2takTx1K" resolve="AStateMachine" />
    </node>
    <node concept="3lhOvk" id="L$vW9Uh$BJ" role="3lj3bC">
      <ref role="30HIoZ" to="gob8:3keuZSaMt2L" resolve="StateMachine" />
      <ref role="3lhOvi" node="P9RR6vlSIH" resolve="DisplayStateMachine" />
    </node>
  </node>
  <node concept="312cEu" id="L$vW9Ug0UE">
    <property role="TrG5h" value="Main" />
    <node concept="2YIFZL" id="L$vW9Ug36a" role="jymVt">
      <property role="TrG5h" value="main" />
      <node concept="3clFbS" id="L$vW9Ug36d" role="3clF47">
        <node concept="3clFbF" id="L$vW9Ug4yU" role="3cqZAp">
          <node concept="2OqwBi" id="L$vW9Ug59A" role="3clFbG">
            <node concept="10M0yZ" id="L$vW9Ug4Ho" role="2Oq$k0">
              <ref role="3cqZAo" to="wyt6:~System.out" resolve="out" />
              <ref role="1PxDUh" to="wyt6:~System" resolve="System" />
            </node>
            <node concept="liA8E" id="L$vW9Ug5QI" role="2OqNvi">
              <ref role="37wK5l" to="guwi:~PrintStream.println(java.lang.String)" resolve="println" />
              <node concept="Xl_RD" id="L$vW9Ug5Wo" role="37wK5m">
                <property role="Xl_RC" value="Executing lightSwitch Mealy FSM" />
              </node>
            </node>
          </node>
        </node>
        <node concept="3cpWs8" id="L$vW9Ug7Wz" role="3cqZAp">
          <node concept="3cpWsn" id="L$vW9Ug7W$" role="3cpWs9">
            <property role="TrG5h" value="fsm" />
            <node concept="3uibUv" id="L$vW9Ug7W_" role="1tU5fm">
              <ref role="3uigEE" node="6uB2takTx1K" resolve="AStateMachine" />
            </node>
            <node concept="2ShNRf" id="L$vW9Ug8Fi" role="33vP2m">
              <node concept="1pGfFk" id="L$vW9Uh6nk" role="2ShVmc">
                <ref role="37wK5l" node="6uB2takTStt" resolve="AStateMachine" />
              </node>
            </node>
          </node>
        </node>
        <node concept="3clFbF" id="L$vW9Ug902" role="3cqZAp">
          <node concept="2OqwBi" id="L$vW9Ug9c4" role="3clFbG">
            <node concept="37vLTw" id="L$vW9Ug900" role="2Oq$k0">
              <ref role="3cqZAo" node="L$vW9Ug7W$" resolve="fsm" />
            </node>
            <node concept="liA8E" id="L$vW9Uh7m8" role="2OqNvi">
              <ref role="37wK5l" node="6uB2takTMGF" resolve="displayState" />
            </node>
          </node>
        </node>
        <node concept="3clFbF" id="L$vW9Uh87d" role="3cqZAp">
          <node concept="2OqwBi" id="L$vW9Uh8um" role="3clFbG">
            <node concept="37vLTw" id="L$vW9Uh87b" role="2Oq$k0">
              <ref role="3cqZAo" node="L$vW9Ug7W$" resolve="fsm" />
            </node>
            <node concept="liA8E" id="L$vW9Uh8Fj" role="2OqNvi">
              <ref role="37wK5l" node="780SfjpvTKa" resolve="onEvent" />
              <node concept="3cmrfG" id="L$vW9Uh8Nz" role="37wK5m">
                <property role="3cmrfH" value="0" />
              </node>
            </node>
          </node>
        </node>
        <node concept="1X3_iC" id="L$vW9Ur4U3" role="lGtFl">
          <property role="3V$3am" value="statement" />
          <property role="3V$3ak" value="f3061a53-9226-4cc5-a443-f952ceaf5816/1068580123136/1068581517665" />
          <node concept="3clFbF" id="L$vW9Uh93w" role="8Wnug">
            <node concept="2OqwBi" id="L$vW9Uh9rR" role="3clFbG">
              <node concept="37vLTw" id="L$vW9Uh93u" role="2Oq$k0">
                <ref role="3cqZAo" node="L$vW9Ug7W$" resolve="fsm" />
              </node>
              <node concept="liA8E" id="L$vW9Uh9_k" role="2OqNvi">
                <ref role="37wK5l" node="6uB2takTMGF" resolve="displayState" />
              </node>
            </node>
          </node>
        </node>
        <node concept="3clFbF" id="L$vW9Uh9Tj" role="3cqZAp">
          <node concept="2OqwBi" id="L$vW9UhaaW" role="3clFbG">
            <node concept="37vLTw" id="L$vW9Uh9Th" role="2Oq$k0">
              <ref role="3cqZAo" node="L$vW9Ug7W$" resolve="fsm" />
            </node>
            <node concept="liA8E" id="L$vW9Uhat6" role="2OqNvi">
              <ref role="37wK5l" node="780SfjpvTKa" resolve="onEvent" />
              <node concept="3cmrfG" id="L$vW9Uha$q" role="37wK5m">
                <property role="3cmrfH" value="1" />
              </node>
            </node>
          </node>
        </node>
        <node concept="1X3_iC" id="L$vW9Ur5gV" role="lGtFl">
          <property role="3V$3am" value="statement" />
          <property role="3V$3ak" value="f3061a53-9226-4cc5-a443-f952ceaf5816/1068580123136/1068581517665" />
          <node concept="3clFbF" id="L$vW9UhaOF" role="8Wnug">
            <node concept="2OqwBi" id="L$vW9Uhb8h" role="3clFbG">
              <node concept="37vLTw" id="L$vW9UhaOD" role="2Oq$k0">
                <ref role="3cqZAo" node="L$vW9Ug7W$" resolve="fsm" />
              </node>
              <node concept="liA8E" id="L$vW9Uhbp2" role="2OqNvi">
                <ref role="37wK5l" node="6uB2takTMGF" resolve="displayState" />
              </node>
            </node>
          </node>
        </node>
        <node concept="3clFbF" id="L$vW9UpT8k" role="3cqZAp">
          <node concept="2OqwBi" id="L$vW9UpT8l" role="3clFbG">
            <node concept="37vLTw" id="L$vW9UpT8m" role="2Oq$k0">
              <ref role="3cqZAo" node="L$vW9Ug7W$" resolve="fsm" />
            </node>
            <node concept="liA8E" id="L$vW9UpT8n" role="2OqNvi">
              <ref role="37wK5l" node="780SfjpvTKa" resolve="onEvent" />
              <node concept="3cmrfG" id="L$vW9UpT8o" role="37wK5m">
                <property role="3cmrfH" value="0" />
              </node>
            </node>
          </node>
        </node>
        <node concept="3clFbF" id="L$vW9UpTGO" role="3cqZAp">
          <node concept="2OqwBi" id="L$vW9UpTGP" role="3clFbG">
            <node concept="37vLTw" id="L$vW9UpTGQ" role="2Oq$k0">
              <ref role="3cqZAo" node="L$vW9Ug7W$" resolve="fsm" />
            </node>
            <node concept="liA8E" id="L$vW9UpTGR" role="2OqNvi">
              <ref role="37wK5l" node="780SfjpvTKa" resolve="onEvent" />
              <node concept="3cmrfG" id="L$vW9UpTGS" role="37wK5m">
                <property role="3cmrfH" value="0" />
              </node>
            </node>
          </node>
        </node>
        <node concept="1X3_iC" id="L$vW9Ur5Hh" role="lGtFl">
          <property role="3V$3am" value="statement" />
          <property role="3V$3ak" value="f3061a53-9226-4cc5-a443-f952ceaf5816/1068580123136/1068581517665" />
          <node concept="3clFbF" id="L$vW9UpUDS" role="8Wnug">
            <node concept="2OqwBi" id="L$vW9UpUDT" role="3clFbG">
              <node concept="37vLTw" id="L$vW9UpUDU" role="2Oq$k0">
                <ref role="3cqZAo" node="L$vW9Ug7W$" resolve="fsm" />
              </node>
              <node concept="liA8E" id="L$vW9UpUDV" role="2OqNvi">
                <ref role="37wK5l" node="6uB2takTMGF" resolve="displayState" />
              </node>
            </node>
          </node>
        </node>
        <node concept="3clFbF" id="L$vW9UpUgi" role="3cqZAp">
          <node concept="2OqwBi" id="L$vW9UpUgj" role="3clFbG">
            <node concept="37vLTw" id="L$vW9UpUgk" role="2Oq$k0">
              <ref role="3cqZAo" node="L$vW9Ug7W$" resolve="fsm" />
            </node>
            <node concept="liA8E" id="L$vW9UpUgl" role="2OqNvi">
              <ref role="37wK5l" node="780SfjpvTKa" resolve="onEvent" />
              <node concept="3cmrfG" id="L$vW9UpUgm" role="37wK5m">
                <property role="3cmrfH" value="0" />
              </node>
            </node>
          </node>
        </node>
        <node concept="3clFbF" id="L$vW9UpVPK" role="3cqZAp">
          <node concept="2OqwBi" id="L$vW9UpVPL" role="3clFbG">
            <node concept="37vLTw" id="L$vW9UpVPM" role="2Oq$k0">
              <ref role="3cqZAo" node="L$vW9Ug7W$" resolve="fsm" />
            </node>
            <node concept="liA8E" id="L$vW9UpVPN" role="2OqNvi">
              <ref role="37wK5l" node="780SfjpvTKa" resolve="onEvent" />
              <node concept="3cmrfG" id="L$vW9UpWhq" role="37wK5m">
                <property role="3cmrfH" value="1" />
              </node>
            </node>
          </node>
        </node>
        <node concept="3clFbF" id="L$vW9UpVmJ" role="3cqZAp">
          <node concept="2OqwBi" id="L$vW9UpVmK" role="3clFbG">
            <node concept="37vLTw" id="L$vW9UpVmL" role="2Oq$k0">
              <ref role="3cqZAo" node="L$vW9Ug7W$" resolve="fsm" />
            </node>
            <node concept="liA8E" id="L$vW9UpVmM" role="2OqNvi">
              <ref role="37wK5l" node="6uB2takTMGF" resolve="displayState" />
            </node>
          </node>
        </node>
      </node>
      <node concept="3Tm1VV" id="L$vW9Ug35L" role="1B3o_S" />
      <node concept="3cqZAl" id="L$vW9Ug35Z" role="3clF45" />
      <node concept="37vLTG" id="L$vW9Ug36$" role="3clF46">
        <property role="TrG5h" value="args" />
        <node concept="10Q1$e" id="L$vW9Ug37T" role="1tU5fm">
          <node concept="3uibUv" id="L$vW9Ug36z" role="10Q1$1">
            <ref role="3uigEE" to="wyt6:~String" resolve="String" />
          </node>
        </node>
      </node>
    </node>
    <node concept="3Tm1VV" id="L$vW9Ug0UF" role="1B3o_S" />
    <node concept="n94m4" id="L$vW9Ug0UG" role="lGtFl">
      <ref role="n9lRv" to="gob8:3keuZSaMt2L" resolve="StateMachine" />
    </node>
  </node>
  <node concept="312cEu" id="6uB2takTx1K">
    <property role="TrG5h" value="AStateMachine" />
    <node concept="2tJIrI" id="52ndNOA$vx7" role="jymVt" />
    <node concept="2tJIrI" id="780SfjpvSlm" role="jymVt" />
    <node concept="312cEg" id="780SfjpvcZy" role="jymVt">
      <property role="TrG5h" value="STATE" />
      <property role="3TUv4t" value="true" />
      <node concept="3Tm6S6" id="780SfjpvcX7" role="1B3o_S" />
      <node concept="10Oyi0" id="780SfjpvcZp" role="1tU5fm" />
      <node concept="3cmrfG" id="780Sfjpvd28" role="33vP2m">
        <property role="3cmrfH" value="0" />
        <node concept="17Uvod" id="780SfjpvfwS" role="lGtFl">
          <property role="2qtEX9" value="value" />
          <property role="P4ACc" value="f3061a53-9226-4cc5-a443-f952ceaf5816/1068580320020/1068580320021" />
          <node concept="3zFVjK" id="780SfjpvfwT" role="3zH0cK">
            <node concept="3clFbS" id="780SfjpvfwU" role="2VODD2">
              <node concept="3clFbF" id="780SfjpvfL2" role="3cqZAp">
                <node concept="2OqwBi" id="780Sfjpvg4c" role="3clFbG">
                  <node concept="30H73N" id="780SfjpvfL1" role="2Oq$k0" />
                  <node concept="2bSWHS" id="780SfjpvgiT" role="2OqNvi" />
                </node>
              </node>
            </node>
          </node>
        </node>
      </node>
      <node concept="1WS0z7" id="L$vW9Ug$$m" role="lGtFl">
        <node concept="3JmXsc" id="L$vW9Ug$$n" role="3Jn$fo">
          <node concept="3clFbS" id="L$vW9Ug$$o" role="2VODD2">
            <node concept="3clFbF" id="L$vW9UgAka" role="3cqZAp">
              <node concept="2OqwBi" id="L$vW9UgAXB" role="3clFbG">
                <node concept="30H73N" id="L$vW9UgAk9" role="2Oq$k0" />
                <node concept="3Tsc0h" id="L$vW9UgC3A" role="2OqNvi">
                  <ref role="3TtcxE" to="gob8:3keuZSaMtco" resolve="state" />
                </node>
              </node>
            </node>
          </node>
        </node>
      </node>
      <node concept="17Uvod" id="780Sfjpve00" role="lGtFl">
        <property role="2qtEX9" value="name" />
        <property role="P4ACc" value="ceab5195-25ea-4f22-9b92-103b95ca8c0c/1169194658468/1169194664001" />
        <node concept="3zFVjK" id="780Sfjpve01" role="3zH0cK">
          <node concept="3clFbS" id="780Sfjpve02" role="2VODD2">
            <node concept="3clFbF" id="780Sfjpve62" role="3cqZAp">
              <node concept="2OqwBi" id="780SfjpveYj" role="3clFbG">
                <node concept="2OqwBi" id="780SfjpveiT" role="2Oq$k0">
                  <node concept="30H73N" id="780Sfjpve61" role="2Oq$k0" />
                  <node concept="3TrcHB" id="780SfjpvexA" role="2OqNvi">
                    <ref role="3TsBF5" to="tpck:h0TrG11" resolve="name" />
                  </node>
                </node>
                <node concept="liA8E" id="780SfjpvfgV" role="2OqNvi">
                  <ref role="37wK5l" to="wyt6:~String.toUpperCase()" resolve="toUpperCase" />
                </node>
              </node>
            </node>
          </node>
        </node>
      </node>
    </node>
    <node concept="312cEg" id="780SfjpvG6k" role="jymVt">
      <property role="TrG5h" value="EVENT" />
      <property role="3TUv4t" value="true" />
      <node concept="3Tm6S6" id="780SfjpvG6l" role="1B3o_S" />
      <node concept="10Oyi0" id="780SfjpvG6m" role="1tU5fm" />
      <node concept="3cmrfG" id="780SfjpvG6n" role="33vP2m">
        <property role="3cmrfH" value="0" />
        <node concept="17Uvod" id="780SfjpvG6o" role="lGtFl">
          <property role="2qtEX9" value="value" />
          <property role="P4ACc" value="f3061a53-9226-4cc5-a443-f952ceaf5816/1068580320020/1068580320021" />
          <node concept="3zFVjK" id="780SfjpvG6p" role="3zH0cK">
            <node concept="3clFbS" id="780SfjpvG6q" role="2VODD2">
              <node concept="3clFbF" id="780SfjpvG6r" role="3cqZAp">
                <node concept="2OqwBi" id="780SfjpvG6s" role="3clFbG">
                  <node concept="30H73N" id="780SfjpvG6t" role="2Oq$k0" />
                  <node concept="2bSWHS" id="780SfjpvG6u" role="2OqNvi" />
                </node>
              </node>
            </node>
          </node>
        </node>
      </node>
      <node concept="1WS0z7" id="780SfjpvG6v" role="lGtFl">
        <node concept="3JmXsc" id="780SfjpvG6w" role="3Jn$fo">
          <node concept="3clFbS" id="780SfjpvG6x" role="2VODD2">
            <node concept="3clFbF" id="780SfjpvHFX" role="3cqZAp">
              <node concept="2OqwBi" id="780SfjpvIbW" role="3clFbG">
                <node concept="30H73N" id="780SfjpvHFW" role="2Oq$k0" />
                <node concept="3Tsc0h" id="780SfjpvIqL" role="2OqNvi">
                  <ref role="3TtcxE" to="gob8:3keuZSaMtcf" resolve="event" />
                </node>
              </node>
            </node>
          </node>
        </node>
      </node>
      <node concept="17Uvod" id="780SfjpvG6A" role="lGtFl">
        <property role="2qtEX9" value="name" />
        <property role="P4ACc" value="ceab5195-25ea-4f22-9b92-103b95ca8c0c/1169194658468/1169194664001" />
        <node concept="3zFVjK" id="780SfjpvG6B" role="3zH0cK">
          <node concept="3clFbS" id="780SfjpvG6C" role="2VODD2">
            <node concept="3clFbF" id="780SfjpvG6D" role="3cqZAp">
              <node concept="2OqwBi" id="780SfjpvG6E" role="3clFbG">
                <node concept="2OqwBi" id="780SfjpvG6F" role="2Oq$k0">
                  <node concept="30H73N" id="780SfjpvG6G" role="2Oq$k0" />
                  <node concept="3TrcHB" id="780SfjpvG6H" role="2OqNvi">
                    <ref role="3TsBF5" to="tpck:h0TrG11" resolve="name" />
                  </node>
                </node>
                <node concept="liA8E" id="780SfjpvG6I" role="2OqNvi">
                  <ref role="37wK5l" to="wyt6:~String.toUpperCase()" resolve="toUpperCase" />
                </node>
              </node>
            </node>
          </node>
        </node>
      </node>
    </node>
    <node concept="312cEg" id="L$vW9UqbR$" role="jymVt">
      <property role="TrG5h" value="ACTION" />
      <property role="3TUv4t" value="true" />
      <node concept="3Tm6S6" id="L$vW9UqbR_" role="1B3o_S" />
      <node concept="10Oyi0" id="L$vW9UqbRA" role="1tU5fm" />
      <node concept="3cmrfG" id="L$vW9UqbRB" role="33vP2m">
        <property role="3cmrfH" value="0" />
        <node concept="17Uvod" id="L$vW9UqbRC" role="lGtFl">
          <property role="2qtEX9" value="value" />
          <property role="P4ACc" value="f3061a53-9226-4cc5-a443-f952ceaf5816/1068580320020/1068580320021" />
          <node concept="3zFVjK" id="L$vW9UqbRD" role="3zH0cK">
            <node concept="3clFbS" id="L$vW9UqbRE" role="2VODD2">
              <node concept="3clFbF" id="L$vW9UqbRF" role="3cqZAp">
                <node concept="2OqwBi" id="L$vW9UqbRG" role="3clFbG">
                  <node concept="30H73N" id="L$vW9UqbRH" role="2Oq$k0" />
                  <node concept="2bSWHS" id="L$vW9UqbRI" role="2OqNvi" />
                </node>
              </node>
            </node>
          </node>
        </node>
      </node>
      <node concept="1WS0z7" id="L$vW9UqbRJ" role="lGtFl">
        <node concept="3JmXsc" id="L$vW9UqbRK" role="3Jn$fo">
          <node concept="3clFbS" id="L$vW9UqbRL" role="2VODD2">
            <node concept="3clFbF" id="L$vW9UqbRM" role="3cqZAp">
              <node concept="2OqwBi" id="L$vW9UqbRN" role="3clFbG">
                <node concept="30H73N" id="L$vW9UqbRO" role="2Oq$k0" />
                <node concept="3Tsc0h" id="L$vW9UqbRP" role="2OqNvi">
                  <ref role="3TtcxE" to="gob8:3keuZSaMtch" resolve="action" />
                </node>
              </node>
            </node>
          </node>
        </node>
      </node>
      <node concept="17Uvod" id="L$vW9UqbRQ" role="lGtFl">
        <property role="2qtEX9" value="name" />
        <property role="P4ACc" value="ceab5195-25ea-4f22-9b92-103b95ca8c0c/1169194658468/1169194664001" />
        <node concept="3zFVjK" id="L$vW9UqbRR" role="3zH0cK">
          <node concept="3clFbS" id="L$vW9UqbRS" role="2VODD2">
            <node concept="3clFbF" id="L$vW9UqbRT" role="3cqZAp">
              <node concept="2OqwBi" id="L$vW9UqbRU" role="3clFbG">
                <node concept="2OqwBi" id="L$vW9UqbRV" role="2Oq$k0">
                  <node concept="30H73N" id="L$vW9UqbRW" role="2Oq$k0" />
                  <node concept="3TrcHB" id="L$vW9UqbRX" role="2OqNvi">
                    <ref role="3TsBF5" to="tpck:h0TrG11" resolve="name" />
                  </node>
                </node>
                <node concept="liA8E" id="L$vW9UqbRY" role="2OqNvi">
                  <ref role="37wK5l" to="wyt6:~String.toUpperCase()" resolve="toUpperCase" />
                </node>
              </node>
            </node>
          </node>
        </node>
      </node>
    </node>
    <node concept="2tJIrI" id="780SfjpvdIb" role="jymVt" />
    <node concept="2tJIrI" id="L$vW9Uqaph" role="jymVt" />
    <node concept="312cEg" id="780Sfjpvp7a" role="jymVt">
      <property role="TrG5h" value="currentState" />
      <node concept="3Tm6S6" id="780SfjpvoIg" role="1B3o_S" />
      <node concept="10Oyi0" id="780Sfjpvp71" role="1tU5fm" />
      <node concept="37vLTw" id="780Sfjpvpwm" role="33vP2m">
        <ref role="3cqZAo" node="780SfjpvcZy" resolve="STATE" />
        <node concept="1ZhdrF" id="780Sfjpvp_X" role="lGtFl">
          <property role="2qtEX8" value="variableDeclaration" />
          <property role="P3scX" value="f3061a53-9226-4cc5-a443-f952ceaf5816/1068498886296/1068581517664" />
          <node concept="3$xsQk" id="780Sfjpvp_Y" role="3$ytzL">
            <node concept="3clFbS" id="780Sfjpvp_Z" role="2VODD2">
              <node concept="3clFbF" id="2CUMcacfO0s" role="3cqZAp">
                <node concept="2OqwBi" id="2CUMcacfPaD" role="3clFbG">
                  <node concept="2OqwBi" id="2CUMcacfODo" role="2Oq$k0">
                    <node concept="2OqwBi" id="2CUMcacfOdx" role="2Oq$k0">
                      <node concept="30H73N" id="2CUMcacfO0r" role="2Oq$k0" />
                      <node concept="3TrEf2" id="L$vW9UgHx2" role="2OqNvi">
                        <ref role="3Tt5mk" to="gob8:4B1pGViInxy" resolve="intialState" />
                      </node>
                    </node>
                    <node concept="3TrcHB" id="2CUMcacfOOi" role="2OqNvi">
                      <ref role="3TsBF5" to="tpck:h0TrG11" resolve="name" />
                    </node>
                  </node>
                  <node concept="liA8E" id="2CUMcacfPsv" role="2OqNvi">
                    <ref role="37wK5l" to="wyt6:~String.toUpperCase()" resolve="toUpperCase" />
                  </node>
                </node>
              </node>
            </node>
          </node>
        </node>
      </node>
    </node>
    <node concept="2tJIrI" id="780SfjpvjtH" role="jymVt" />
    <node concept="3clFbW" id="6uB2takTStt" role="jymVt">
      <node concept="3cqZAl" id="6uB2takTStv" role="3clF45" />
      <node concept="3Tm1VV" id="6uB2takTStw" role="1B3o_S" />
      <node concept="3clFbS" id="6uB2takTStx" role="3clF47" />
    </node>
    <node concept="2tJIrI" id="6uB2takU1ZJ" role="jymVt" />
    <node concept="3clFb_" id="6uB2takTMGF" role="jymVt">
      <property role="TrG5h" value="displayState" />
      <node concept="3cqZAl" id="6uB2takTMGH" role="3clF45" />
      <node concept="3Tm1VV" id="6uB2takTMGI" role="1B3o_S" />
      <node concept="3clFbS" id="6uB2takTMGJ" role="3clF47">
        <node concept="3cpWs8" id="52ndNOA$K5R" role="3cqZAp">
          <node concept="3cpWsn" id="52ndNOA$K5S" role="3cpWs9">
            <property role="TrG5h" value="stateName" />
            <node concept="3uibUv" id="52ndNOA$K5T" role="1tU5fm">
              <ref role="3uigEE" to="wyt6:~String" resolve="String" />
            </node>
            <node concept="Xl_RD" id="52ndNOA$Lxz" role="33vP2m" />
          </node>
        </node>
        <node concept="3KaCP$" id="52ndNOA$$QM" role="3cqZAp">
          <node concept="3KbdKl" id="52ndNOA$$QN" role="3KbHQx">
            <node concept="37vLTw" id="52ndNOA$$QO" role="3Kbmr1">
              <ref role="3cqZAo" node="780SfjpvcZy" resolve="STATE" />
            </node>
            <node concept="3clFbS" id="52ndNOA$$QP" role="3Kbo56">
              <node concept="3clFbF" id="52ndNOA$ENv" role="3cqZAp">
                <node concept="2OqwBi" id="52ndNOA$ENw" role="3clFbG">
                  <node concept="10M0yZ" id="52ndNOA$ENx" role="2Oq$k0">
                    <ref role="1PxDUh" to="wyt6:~System" resolve="System" />
                    <ref role="3cqZAo" to="wyt6:~System.out" resolve="out" />
                  </node>
                  <node concept="liA8E" id="52ndNOA$ENy" role="2OqNvi">
                    <ref role="37wK5l" to="guwi:~PrintStream.println(java.lang.String)" resolve="println" />
                    <node concept="3cpWs3" id="2CUMcacgd2o" role="37wK5m">
                      <node concept="Xl_RD" id="52ndNOA$ENz" role="3uHU7B">
                        <property role="Xl_RC" value="Current State: " />
                      </node>
                      <node concept="Xl_RD" id="2CUMcacglGh" role="3uHU7w">
                        <property role="Xl_RC" value="State" />
                        <node concept="17Uvod" id="2CUMcacgmBN" role="lGtFl">
                          <property role="2qtEX9" value="value" />
                          <property role="P4ACc" value="f3061a53-9226-4cc5-a443-f952ceaf5816/1070475926800/1070475926801" />
                          <node concept="3zFVjK" id="2CUMcacgmBO" role="3zH0cK">
                            <node concept="3clFbS" id="2CUMcacgmBP" role="2VODD2">
                              <node concept="3clFbF" id="2CUMcacgnyC" role="3cqZAp">
                                <node concept="2OqwBi" id="2CUMcacgoml" role="3clFbG">
                                  <node concept="30H73N" id="2CUMcacgnyB" role="2Oq$k0" />
                                  <node concept="3TrcHB" id="2CUMcacgoOR" role="2OqNvi">
                                    <ref role="3TsBF5" to="tpck:h0TrG11" resolve="name" />
                                  </node>
                                </node>
                              </node>
                            </node>
                          </node>
                        </node>
                      </node>
                    </node>
                  </node>
                </node>
              </node>
              <node concept="3zACq4" id="52ndNOA$$QQ" role="3cqZAp" />
            </node>
            <node concept="1WS0z7" id="52ndNOA$$QR" role="lGtFl">
              <node concept="3JmXsc" id="52ndNOA$$QS" role="3Jn$fo">
                <node concept="3clFbS" id="52ndNOA$$QT" role="2VODD2">
                  <node concept="3clFbF" id="52ndNOA$$QU" role="3cqZAp">
                    <node concept="2OqwBi" id="52ndNOA$$QV" role="3clFbG">
                      <node concept="3Tsc0h" id="52ndNOA$$QW" role="2OqNvi">
                        <ref role="3TtcxE" to="gob8:3keuZSaMtco" resolve="state" />
                      </node>
                      <node concept="30H73N" id="52ndNOA$$QX" role="2Oq$k0" />
                    </node>
                  </node>
                </node>
              </node>
            </node>
          </node>
          <node concept="37vLTw" id="52ndNOA$$QY" role="3KbGdf">
            <ref role="3cqZAo" node="780Sfjpvp7a" resolve="currentState" />
          </node>
        </node>
      </node>
    </node>
    <node concept="2tJIrI" id="780SfjpvSS7" role="jymVt" />
    <node concept="3clFb_" id="780SfjpvTKa" role="jymVt">
      <property role="TrG5h" value="onEvent" />
      <node concept="3clFbS" id="780SfjpvTKd" role="3clF47">
        <node concept="3KaCP$" id="780SfjpvUgm" role="3cqZAp">
          <node concept="3KbdKl" id="780SfjpvU$J" role="3KbHQx">
            <node concept="37vLTw" id="780SfjpvVf1" role="3Kbmr1">
              <ref role="3cqZAo" node="780SfjpvcZy" resolve="STATE" />
            </node>
            <node concept="3clFbS" id="780SfjpvVpg" role="3Kbo56">
              <node concept="3KaCP$" id="2CUMcacft3x" role="3cqZAp">
                <node concept="3KbdKl" id="2CUMcacftuR" role="3KbHQx">
                  <node concept="37vLTw" id="2CUMcacfyQi" role="3Kbmr1">
                    <ref role="3cqZAo" node="780SfjpvG6k" resolve="EVENT" />
                    <node concept="1ZhdrF" id="P9RR6vlo55" role="lGtFl">
                      <property role="2qtEX8" value="variableDeclaration" />
                      <property role="P3scX" value="f3061a53-9226-4cc5-a443-f952ceaf5816/1068498886296/1068581517664" />
                      <node concept="3$xsQk" id="P9RR6vlo56" role="3$ytzL">
                        <node concept="3clFbS" id="P9RR6vlo57" role="2VODD2">
                          <node concept="3clFbF" id="P9RR6vlpc$" role="3cqZAp">
                            <node concept="2OqwBi" id="P9RR6vlHJC" role="3clFbG">
                              <node concept="2OqwBi" id="P9RR6vlrdN" role="2Oq$k0">
                                <node concept="2OqwBi" id="P9RR6vlpQC" role="2Oq$k0">
                                  <node concept="30H73N" id="P9RR6vlpcz" role="2Oq$k0" />
                                  <node concept="3TrEf2" id="P9RR6vlqsq" role="2OqNvi">
                                    <ref role="3Tt5mk" to="gob8:4B1pGViInxB" resolve="event" />
                                  </node>
                                </node>
                                <node concept="3TrcHB" id="P9RR6vls$d" role="2OqNvi">
                                  <ref role="3TsBF5" to="tpck:h0TrG11" resolve="name" />
                                </node>
                              </node>
                              <node concept="liA8E" id="P9RR6vlJ0S" role="2OqNvi">
                                <ref role="37wK5l" to="wyt6:~String.toUpperCase()" resolve="toUpperCase" />
                              </node>
                            </node>
                          </node>
                        </node>
                      </node>
                    </node>
                  </node>
                  <node concept="1WS0z7" id="2CUMcacfuHr" role="lGtFl">
                    <node concept="3JmXsc" id="2CUMcacfuHu" role="3Jn$fo">
                      <node concept="3clFbS" id="2CUMcacfuHv" role="2VODD2">
                        <node concept="3clFbF" id="2CUMcacfuH_" role="3cqZAp">
                          <node concept="2OqwBi" id="2CUMcacfuHw" role="3clFbG">
                            <node concept="3Tsc0h" id="2CUMcacfuHz" role="2OqNvi">
                              <ref role="3TtcxE" to="gob8:4B1pGViImLa" resolve="transition" />
                            </node>
                            <node concept="30H73N" id="2CUMcacfuH$" role="2Oq$k0" />
                          </node>
                        </node>
                      </node>
                    </node>
                  </node>
                  <node concept="3clFbS" id="2CUMcacfBbC" role="3Kbo56">
                    <node concept="3clFbF" id="2CUMcacfC40" role="3cqZAp">
                      <node concept="2OqwBi" id="2CUMcacfC41" role="3clFbG">
                        <node concept="10M0yZ" id="2CUMcacfC42" role="2Oq$k0">
                          <ref role="3cqZAo" to="wyt6:~System.out" resolve="out" />
                          <ref role="1PxDUh" to="wyt6:~System" resolve="System" />
                        </node>
                        <node concept="liA8E" id="2CUMcacfC43" role="2OqNvi">
                          <ref role="37wK5l" to="guwi:~PrintStream.println(java.lang.String)" resolve="println" />
                          <node concept="3cpWs3" id="L$vW9UqkC$" role="37wK5m">
                            <node concept="Xl_RD" id="L$vW9Uqllf" role="3uHU7w">
                              <property role="Xl_RC" value="Action" />
                              <node concept="17Uvod" id="L$vW9UqJHp" role="lGtFl">
                                <property role="2qtEX9" value="value" />
                                <property role="P4ACc" value="f3061a53-9226-4cc5-a443-f952ceaf5816/1070475926800/1070475926801" />
                                <node concept="3zFVjK" id="L$vW9UqJHq" role="3zH0cK">
                                  <node concept="3clFbS" id="L$vW9UqJHr" role="2VODD2">
                                    <node concept="3clFbF" id="L$vW9UqKTn" role="3cqZAp">
                                      <node concept="2OqwBi" id="L$vW9UqQDB" role="3clFbG">
                                        <node concept="2OqwBi" id="L$vW9UqMmA" role="2Oq$k0">
                                          <node concept="30H73N" id="L$vW9UqKTm" role="2Oq$k0" />
                                          <node concept="3TrEf2" id="L$vW9UqPrb" role="2OqNvi">
                                            <ref role="3Tt5mk" to="gob8:4B1pGViInPs" resolve="action" />
                                          </node>
                                        </node>
                                        <node concept="3TrcHB" id="L$vW9UqSiK" role="2OqNvi">
                                          <ref role="3TsBF5" to="tpck:h0TrG11" resolve="name" />
                                        </node>
                                      </node>
                                    </node>
                                  </node>
                                </node>
                              </node>
                            </node>
                            <node concept="3cpWs3" id="L$vW9UqgQi" role="3uHU7B">
                              <node concept="3cpWs3" id="2CUMcacgB76" role="3uHU7B">
                                <node concept="3cpWs3" id="2CUMcacgzyp" role="3uHU7B">
                                  <node concept="3cpWs3" id="2CUMcacgu0b" role="3uHU7B">
                                    <node concept="Xl_RD" id="2CUMcacfC44" role="3uHU7B">
                                      <property role="Xl_RC" value="  On Event: " />
                                    </node>
                                    <node concept="Xl_RD" id="2CUMcacguk5" role="3uHU7w">
                                      <property role="Xl_RC" value="Event" />
                                      <node concept="17Uvod" id="2CUMcacgv3p" role="lGtFl">
                                        <property role="2qtEX9" value="value" />
                                        <property role="P4ACc" value="f3061a53-9226-4cc5-a443-f952ceaf5816/1070475926800/1070475926801" />
                                        <node concept="3zFVjK" id="2CUMcacgv3q" role="3zH0cK">
                                          <node concept="3clFbS" id="2CUMcacgv3r" role="2VODD2">
                                            <node concept="3clFbF" id="2CUMcacgvn9" role="3cqZAp">
                                              <node concept="2OqwBi" id="2CUMcacgxU1" role="3clFbG">
                                                <node concept="2OqwBi" id="2CUMcacgwdD" role="2Oq$k0">
                                                  <node concept="30H73N" id="2CUMcacgvn8" role="2Oq$k0" />
                                                  <node concept="3TrEf2" id="2CUMcacgxo8" role="2OqNvi">
                                                    <ref role="3Tt5mk" to="gob8:4B1pGViInxB" resolve="event" />
                                                  </node>
                                                </node>
                                                <node concept="3TrcHB" id="2CUMcacgyo$" role="2OqNvi">
                                                  <ref role="3TsBF5" to="tpck:h0TrG11" resolve="name" />
                                                </node>
                                              </node>
                                            </node>
                                          </node>
                                        </node>
                                      </node>
                                    </node>
                                  </node>
                                  <node concept="Xl_RD" id="2CUMcacg$lH" role="3uHU7w">
                                    <property role="Xl_RC" value=" moved to State: " />
                                  </node>
                                </node>
                                <node concept="Xl_RD" id="2CUMcacgBto" role="3uHU7w">
                                  <property role="Xl_RC" value="State" />
                                  <node concept="17Uvod" id="2CUMcacgEds" role="lGtFl">
                                    <property role="2qtEX9" value="value" />
                                    <property role="P4ACc" value="f3061a53-9226-4cc5-a443-f952ceaf5816/1070475926800/1070475926801" />
                                    <node concept="3zFVjK" id="2CUMcacgEdt" role="3zH0cK">
                                      <node concept="3clFbS" id="2CUMcacgEdu" role="2VODD2">
                                        <node concept="3clFbF" id="2CUMcacgEz3" role="3cqZAp">
                                          <node concept="2OqwBi" id="2CUMcacgJNV" role="3clFbG">
                                            <node concept="2OqwBi" id="2CUMcacgIDR" role="2Oq$k0">
                                              <node concept="30H73N" id="2CUMcacgEz2" role="2Oq$k0" />
                                              <node concept="3TrEf2" id="2CUMcacgJ3U" role="2OqNvi">
                                                <ref role="3Tt5mk" to="gob8:4B1pGViInxE" resolve="target" />
                                              </node>
                                            </node>
                                            <node concept="3TrcHB" id="2CUMcacgKWz" role="2OqNvi">
                                              <ref role="3TsBF5" to="tpck:h0TrG11" resolve="name" />
                                            </node>
                                          </node>
                                        </node>
                                      </node>
                                    </node>
                                  </node>
                                </node>
                              </node>
                              <node concept="Xl_RD" id="L$vW9Uqil1" role="3uHU7w">
                                <property role="Xl_RC" value=" with action " />
                              </node>
                            </node>
                          </node>
                        </node>
                      </node>
                    </node>
                    <node concept="3clFbF" id="2CUMcacfGov" role="3cqZAp">
                      <node concept="37vLTI" id="2CUMcacfIWR" role="3clFbG">
                        <node concept="2OqwBi" id="2CUMcacfH3k" role="37vLTJ">
                          <node concept="Xjq3P" id="2CUMcacfGot" role="2Oq$k0" />
                          <node concept="2OwXpG" id="2CUMcacfHZC" role="2OqNvi">
                            <ref role="2Oxat5" node="780Sfjpvp7a" resolve="currentState" />
                          </node>
                        </node>
                        <node concept="37vLTw" id="2CUMcacfTPF" role="37vLTx">
                          <ref role="3cqZAo" node="780SfjpvcZy" resolve="STATE" />
                          <node concept="1ZhdrF" id="2CUMcacfUli" role="lGtFl">
                            <property role="2qtEX8" value="variableDeclaration" />
                            <property role="P3scX" value="f3061a53-9226-4cc5-a443-f952ceaf5816/1068498886296/1068581517664" />
                            <node concept="3$xsQk" id="2CUMcacfUlj" role="3$ytzL">
                              <node concept="3clFbS" id="2CUMcacfUlk" role="2VODD2">
                                <node concept="3clFbF" id="2CUMcacfUSH" role="3cqZAp">
                                  <node concept="2OqwBi" id="2CUMcacfYHR" role="3clFbG">
                                    <node concept="2OqwBi" id="2CUMcacfXsa" role="2Oq$k0">
                                      <node concept="2OqwBi" id="2CUMcacfVEz" role="2Oq$k0">
                                        <node concept="30H73N" id="2CUMcacfUSG" role="2Oq$k0" />
                                        <node concept="3TrEf2" id="2CUMcacfW6T" role="2OqNvi">
                                          <ref role="3Tt5mk" to="gob8:4B1pGViInxE" resolve="target" />
                                        </node>
                                      </node>
                                      <node concept="3TrcHB" id="2CUMcacfXRe" role="2OqNvi">
                                        <ref role="3TsBF5" to="tpck:h0TrG11" resolve="name" />
                                      </node>
                                    </node>
                                    <node concept="liA8E" id="2CUMcacfZdP" role="2OqNvi">
                                      <ref role="37wK5l" to="wyt6:~String.toUpperCase()" resolve="toUpperCase" />
                                    </node>
                                  </node>
                                </node>
                              </node>
                            </node>
                          </node>
                        </node>
                      </node>
                    </node>
                    <node concept="3zACq4" id="P9RR6vmjmn" role="3cqZAp" />
                  </node>
                </node>
                <node concept="37vLTw" id="2CUMcacfthh" role="3KbGdf">
                  <ref role="3cqZAo" node="780SfjpvTVG" resolve="event" />
                </node>
              </node>
              <node concept="3zACq4" id="780SfjpvVzP" role="3cqZAp" />
            </node>
            <node concept="1WS0z7" id="780SfjpvVKS" role="lGtFl">
              <node concept="3JmXsc" id="780SfjpvVKV" role="3Jn$fo">
                <node concept="3clFbS" id="780SfjpvVKW" role="2VODD2">
                  <node concept="3clFbF" id="780SfjpvVL2" role="3cqZAp">
                    <node concept="2OqwBi" id="780SfjpvVKX" role="3clFbG">
                      <node concept="3Tsc0h" id="780SfjpvVL0" role="2OqNvi">
                        <ref role="3TtcxE" to="gob8:3keuZSaMtco" resolve="state" />
                      </node>
                      <node concept="30H73N" id="780SfjpvVL1" role="2Oq$k0" />
                    </node>
                  </node>
                </node>
              </node>
            </node>
          </node>
          <node concept="37vLTw" id="780SfjpvUqE" role="3KbGdf">
            <ref role="3cqZAo" node="780Sfjpvp7a" resolve="currentState" />
          </node>
        </node>
      </node>
      <node concept="3Tm1VV" id="780SfjpvT4U" role="1B3o_S" />
      <node concept="3cqZAl" id="780SfjpvTK1" role="3clF45" />
      <node concept="37vLTG" id="780SfjpvTVG" role="3clF46">
        <property role="TrG5h" value="event" />
        <node concept="10Oyi0" id="780SfjpvTVF" role="1tU5fm" />
      </node>
    </node>
    <node concept="2tJIrI" id="780SfjpuSkq" role="jymVt" />
    <node concept="3Tm1VV" id="6uB2takTx1L" role="1B3o_S" />
    <node concept="n94m4" id="6uB2takTx1M" role="lGtFl">
      <ref role="n9lRv" to="gob8:3keuZSaMt2L" resolve="StateMachine" />
    </node>
    <node concept="17Uvod" id="52ndNOA$gLF" role="lGtFl">
      <property role="2qtEX9" value="name" />
      <property role="P4ACc" value="ceab5195-25ea-4f22-9b92-103b95ca8c0c/1169194658468/1169194664001" />
      <node concept="3zFVjK" id="52ndNOA$gLG" role="3zH0cK">
        <node concept="3clFbS" id="52ndNOA$gLH" role="2VODD2">
          <node concept="3clFbF" id="52ndNOA$hs3" role="3cqZAp">
            <node concept="2OqwBi" id="52ndNOA$hCZ" role="3clFbG">
              <node concept="30H73N" id="52ndNOA$hs2" role="2Oq$k0" />
              <node concept="3TrcHB" id="52ndNOA$hRp" role="2OqNvi">
                <ref role="3TsBF5" to="tpck:h0TrG11" resolve="name" />
              </node>
            </node>
          </node>
        </node>
      </node>
    </node>
  </node>
  <node concept="312cEu" id="P9RR6vlSIH">
    <property role="TrG5h" value="DisplayStateMachine" />
    <node concept="3clFb_" id="P9RR6vlSKI" role="jymVt">
      <property role="TrG5h" value="display" />
      <node concept="3cqZAl" id="P9RR6vlSKK" role="3clF45" />
      <node concept="3Tm1VV" id="P9RR6vlSKL" role="1B3o_S" />
      <node concept="3clFbS" id="P9RR6vlSKM" role="3clF47">
        <node concept="3clFbF" id="P9RR6vlTPR" role="3cqZAp">
          <node concept="2OqwBi" id="P9RR6vlUem" role="3clFbG">
            <node concept="10M0yZ" id="P9RR6vlTRl" role="2Oq$k0">
              <ref role="3cqZAo" to="wyt6:~System.out" resolve="out" />
              <ref role="1PxDUh" to="wyt6:~System" resolve="System" />
            </node>
            <node concept="liA8E" id="P9RR6vlU$M" role="2OqNvi">
              <ref role="37wK5l" to="guwi:~PrintStream.println(java.lang.String)" resolve="println" />
              <node concept="Xl_RD" id="P9RR6vlU_I" role="37wK5m">
                <property role="Xl_RC" value="Display State Machine" />
              </node>
            </node>
          </node>
        </node>
      </node>
    </node>
    <node concept="3Tm1VV" id="P9RR6vlSII" role="1B3o_S" />
    <node concept="n94m4" id="P9RR6vlSIJ" role="lGtFl">
      <ref role="n9lRv" to="gob8:3keuZSaMt2L" resolve="StateMachine" />
    </node>
  </node>
</model>

